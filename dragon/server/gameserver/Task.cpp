/*
 * =====================================================================================
 *
 *       Filename:  Task.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/14/2014 07:05:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Task.h"
#include "Role.h"
#include "CmdDefine.h"
#include "EnumDefines.h"
#include "ErrorMsg.h"
#include "ConfigData.h"
#include "CommonConfig.h"
#include "Timer.h"

/*
 *--------------------------------------------------------------------------------------
 *       Class:  CTask
 *      Method:  CTask
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
CTask::CTask ()
{
}  /* -----  end of method CTask::CTask  (constructor)  ----- */

CTask::~CTask()
{
}

int
CTask::Init (CRole *pCRole)
{
	m_pCRole = pCRole;
	if (LoadData())
	{
		IME_ERROR("load task data fail userid %u", m_pCRole->GetdwAccountId());
		return -1;
	}
	return 0;
}		/* -----  end of method CTask::Init  ----- */

void
CTask::SerilizeDB (ByteBuffer &pkg)
{
	pkg << (uint32_t) m_mapTask.size();
	std::map<uint32_t, TaskData>::iterator it;
	for (it = m_mapTask.begin(); it != m_mapTask.end(); it++)
	{
		pkg << it->first;
		pkg << it->second.PassTime;
		pkg << it->second.Number;
		pkg << it->second.FlushTime;
	}
	pkg << (uint32_t) m_PreviewCombatPacket.size();
	pkg.append(m_PreviewCombatPacket.contents(), m_PreviewCombatPacket.size());
	return ;
}		/* -----  end of method CTask::SerilizeDb  ----- */

void
CTask::DeSerilizeDB (ByteBuffer &pkg)
{
	m_mapTask.clear();
	m_PreviewCombatPacket.clear();
	uint32_t number;
	uint32_t key;
	TaskData tmp;
	pkg >> number;
	IME_LOG("total number1 %u", number);
	for (unsigned int i = 0; i < number; i++)
	{
		pkg >> key;
		pkg >> tmp.PassTime;
		pkg >> tmp.Number;
		pkg >> tmp.FlushTime;
		m_mapTask[key] = tmp;
	}
	pkg >> number;
	IME_LOG("total number2 %u", number);
	std::string temp;
	pkg.read(temp, number);
	m_PreviewCombatPacket.append(temp.c_str(), number);
	return ;
}		/* -----  end of method CTask::DeSerilizeDB  ----- */

int
CTask::LoadData ()
{
	std::string temp;
	if (!CDBCtrl::GetUserTaskData(temp, m_pCRole->GetdwAccountId()))
	{
		IME_ERROR("get data fail userid %u", m_pCRole->GetdwAccountId());
		return -1;
	}
	ByteBuffer by;
	by.append(temp.c_str(), temp.size());
	DeSerilizeDB(by);
	return 0;
}		/* -----  end of method CTask::LoadData  ----- */

void
CTask::SaveData ()
{
	std::string temp;
	ByteBuffer by;
	DeSerilizeDB(by);
	temp.append((const char *)by.contents(), by.size());
	CDBCtrl::SaveUserTaskData(temp, m_pCRole->GetdwAccountId());
	return ;
}		/* -----  end of method CTask::SaveData  ----- */

void
CTask::HandlerCombatPreview (WorldPacket &packet)
{
	uint32 index;
	packet >> index;
	IME_CHAR_LOG(m_pCRole->GetdwAccountId(), "ACTION", "desc=combat preview task index %u", index);
	PACKET_REMAIN_CHECK_NO_ROLE(packet, CMD_SC_TASK_COMBAT_PREVIEW_RESULT, m_pCRole);

	const STC_CONF_AREA *pConf = CConfArea::Find(index);
	if (pConf == NULL)
	{
		IME_ERROR("load area csv fail index %u", index);
		m_pCRole->SendErrorMsg(ERRNO_MSG_CSV_LOAD, CMD_SC_TASK_COMBAT_PREVIEW_RESULT);
		return;
	}
	if (pConf->wType == BRANCH_TASK)
	{
		if (m_mapTask.find(pConf->dwNeedTaskIndex) != m_mapTask.end())
		{
			IME_ERROR("can not find task index %u", pConf->dwNeedTaskIndex);
			m_pCRole->SendErrorMsg(ERRNO_MSG_CSV_LOAD, CMD_SC_TASK_COMBAT_PREVIEW_RESULT);
			return;
		}
	}
	std::map<uint32_t, TaskData>::iterator it = m_mapTask.find(index);
	if (it != m_mapTask.end())
	{
		if (it->second.PassTime + pConf->dwCD >= time(NULL))
		{
			IME_ERROR("mission is in CD");
			m_pCRole->SendErrorMsg(ERRNO_MSG_IN_CD, CMD_SC_TASK_COMBAT_PREVIEW_RESULT);
			return;
		}
		if (pConf->dwChallengeNumber != 0 && it->second.Number >= pConf->dwChallengeNumber)
		{
			m_pCRole->SendErrorMsg(ERRNO_MSG_AREA_MAX_COUNT, CMD_SC_TASK_COMBAT_PREVIEW_RESULT);
			return;
		}
	}
	if (m_pCRole->GetwLevel() < pConf->wLevelLimit)
	{
		m_pCRole->SendErrorMsg(ERRNO_MSG_AREA_LEVEL, CMD_SC_TASK_COMBAT_PREVIEW_RESULT);
		return;
	}
	if (m_pCRole->GetdwEnergy() < pConf->wEnergyConsume)
	{
		m_pCRole->SendEnergyNotEnough(CMD_SC_TASK_COMBAT_PREVIEW_RESULT);
		return;
	}

	std::vector<NPCData> vecnpc;
	uint32_t batch = 1;
	std::vector<uint32_t> vecindex;
	std::vector<uint32_t> vecnumber;
	for (unsigned int m = 0; m < MAX_AREA_NPC; m++)
	{
		uint32_t npcid = pConf->dwNPCId[m];
		if (npcid == 0)
			continue;
		const STC_CONF_NPC *pNPC = CConfNPC::Find(npcid);
		if (pNPC == NULL)
		{
			IME_ERROR("can not find npc index %u", npcid);
			m_pCRole->SendErrorMsg(ERRNO_MSG_CSV_LOAD, CMD_SC_TASK_COMBAT_PREVIEW_RESULT);
			return;
		}
		if (m_mapTask.find(index) == m_mapTask.end())
		{
			for (unsigned int i = 0; i < MAX_AREA_FIRST_DROP; i++)
			{
				if (pConf->dwFirstDropIndex[i] != 0)
				{
					vecindex.push_back(pConf->dwFirstDropIndex[i]);
					vecnumber.push_back(pConf->dwFirstNumber[i]);
				}
			}
		}

		for (unsigned int i = 0; i < MAX_NPC_MONSTER; i++)
		{
			if (pNPC->dwNPCId[i] != 0)
			{
				NPCData npca;
				npca.wBatchId = batch;
				npca.dwNPCId = pNPC->dwNPCId[i];
				npca.wPos = pNPC->wPos[i];
				npca.wLevel = pNPC->wLevel;
				const STC_CONF_HERO *pHero = CConfHero::Find(pNPC->dwNPCId[i]);
				if (pHero == NULL)
				{
					IME_ERROR("can not find hero in npc index %u npcid %u", pNPC->dwIndex, pNPC->dwNPCId[i]);
					m_pCRole->SendErrorMsg(ERRNO_MSG_CSV_LOAD, CMD_SC_TASK_COMBAT_PREVIEW_RESULT);
					return;
				}
				npca.dwAttack = pNPC->dwAttack[i]; 
				npca.dwDefence = pNPC->dwDefence[i]; 
				npca.dwHealth = pNPC->dwHealth[i]; 

				uint32_t rule[] = {DROP_BY_DIRECT, 0, pNPC->dwPro[i]};
				uint32_t data[][1][3] = {
					{{(uint32_t)ITEM, pNPC->dwDropIndex[i], pNPC->dwDropNumber[i]}}
				};
				std::vector< std::vector<uint32_t> > vecRule;
				std::vector< std::vector<OneProduct> > vecData;
				ONE_RULE_ARRAY_TO_VECTOR(rule, vecRule);
				DATA_ARRAY_TO_VECTOR(data, 1, 3, vecData);
				DropData comm;
				std::vector<OneProduct> result = GetDropGroupId(vecRule, vecData, comm);
				if (result.empty())
				{
					npca.dwDropIndex = 0;
					npca.dwDropNumber = 0;
				}
				else
				{
					npca.dwDropIndex = pNPC->dwDropIndex[i];
					npca.dwDropNumber = pNPC->dwDropNumber[i];
				}
				npca.dwNormalAttackIndex = pHero->dwSkillId[0];

				vecnpc.push_back(npca);
			}
		}
		batch++;
	}

	m_PreviewCombatPacket.clear();
	m_PreviewCombatPacket << index;
	m_PreviewCombatPacket << (uint32_t)vecindex.size();
	for (unsigned int i = 0; i < vecindex.size(); i++)
	{
		m_PreviewCombatPacket << vecindex[i];
		m_PreviewCombatPacket << vecnumber[i];
	}
	m_PreviewCombatPacket << (uint32_t)(pConf->dwCoin / ((uint32_t)vecnpc.size() == 0 ? 1 : (uint32_t) vecnpc.size()) );
	m_PreviewCombatPacket << (uint32_t) pConf->dwCoin;
	m_PreviewCombatPacket << (uint32_t)vecnpc.size();
	for (unsigned int i = 0; i < vecnpc.size(); i++)
	{
		m_PreviewCombatPacket << vecnpc[i].wBatchId;
	   	m_PreviewCombatPacket << (uint32_t) i + 1;
	   	m_PreviewCombatPacket << vecnpc[i].dwNPCId;
		m_PreviewCombatPacket << vecnpc[i].wPos;
		m_PreviewCombatPacket << vecnpc[i].wLevel;
		m_PreviewCombatPacket << vecnpc[i].dwAttack;
		m_PreviewCombatPacket << vecnpc[i].dwDefence;
		m_PreviewCombatPacket << vecnpc[i].dwHealth;
		m_PreviewCombatPacket << vecnpc[i].dwDropIndex;
		m_PreviewCombatPacket << vecnpc[i].dwDropNumber;
		m_PreviewCombatPacket << vecnpc[i].dwNormalAttackIndex;
	}

	WorldPacket info(CMD_SC_TASK_COMBAT_PREVIEW_RESULT);
	info << (uint16_t) 0;
	info.append(m_PreviewCombatPacket.contents(), m_PreviewCombatPacket.size());
	m_pCRole->SendPacket(&info);
	return ;
}		/* -----  end of method CTask::HandlerCombatPreview  ----- */

void
CTask::HandlerCombatResult (WorldPacket &packet)
{
	uint32 index;
	uint8 result;
	packet >> index;
	packet >> result;
	IME_CHAR_LOG(m_pCRole->GetdwAccountId(), "ACTION", "desc=combat task index %u, result %u", index, result);
	PACKET_REMAIN_CHECK_NO_ROLE(packet, CMD_SC_TASK_COMBAT_RESULT, m_pCRole);

	if (m_PreviewCombatPacket.empty())
	{
		IME_ERROR("have no request preview before combat");
		m_pCRole->SendErrorMsg(ERRNO_MSG_SYS, CMD_SC_TASK_COMBAT_RESULT);
		return;
	}

	const STC_CONF_AREA *pConf = CConfArea::Find(index);
	if (pConf == NULL)
	{
		IME_ERROR("load area csv fail index %u", index);
		m_pCRole->SendErrorMsg(ERRNO_MSG_CSV_LOAD, CMD_SC_TASK_COMBAT_RESULT);
		return;
	}
	if (pConf->wType == BRANCH_TASK)
	{
		if (m_mapTask.find(pConf->dwNeedTaskIndex) != m_mapTask.end())
		{
			IME_ERROR("can not find task index %u", pConf->dwNeedTaskIndex);
			m_pCRole->SendErrorMsg(ERRNO_MSG_CSV_LOAD, CMD_SC_TASK_COMBAT_RESULT);
			return;
		}
	}
	std::map<uint32_t, TaskData>::iterator it = m_mapTask.find(index);
	if (it != m_mapTask.end())
	{
		if (it->second.PassTime + pConf->dwCD >= time(NULL))
		{
			IME_ERROR("mission is in CD");
			m_pCRole->SendErrorMsg(ERRNO_MSG_IN_CD, CMD_SC_TASK_COMBAT_RESULT);
			return;
		}
		if (pConf->dwChallengeNumber != 0 && it->second.Number >= pConf->dwChallengeNumber)
		{
			m_pCRole->SendErrorMsg(ERRNO_MSG_AREA_MAX_COUNT, CMD_SC_TASK_COMBAT_RESULT);
			return;
		}
	}
	if (m_pCRole->GetwLevel() < pConf->wLevelLimit)
	{
		m_pCRole->SendErrorMsg(ERRNO_MSG_AREA_LEVEL, CMD_SC_TASK_COMBAT_RESULT);
		return;
	}
	if (m_pCRole->GetdwEnergy() < pConf->wEnergyConsume)
	{
		m_pCRole->SendEnergyNotEnough(CMD_SC_TASK_COMBAT_RESULT);
		return;
	}


	OneProduct tmp;
	uint32_t val;
	std::vector< OneProduct > vecproduct;
	ByteBuffer view;
	view = m_PreviewCombatPacket;
	uint32_t preindex;
	view >> preindex;
	uint32_t number;
	view >> number;
	for (unsigned int i = 0; i < number; i++)
	{
		tmp.clear();
		tmp.push_back(ITEM);
		view >> val;
		tmp.push_back(val);	
		view >> val;
		tmp.push_back(val);
		vecproduct.push_back(tmp);
	}
	view >> val;
	view >> val;
	view >> number;
	NPCData npc;
	for (unsigned int i = 0; i < number; i++)
	{
		view >> npc.wBatchId;
		view >> val;
	   	view >> npc.dwNPCId;
		view >> npc.wPos;
		view >> npc.wLevel;
		view >> npc.dwAttack;
		view >> npc.dwDefence;
		view >> npc.dwHealth;
		view >> npc.dwDropIndex;
		view >> npc.dwDropNumber;
		view >> npc.dwNormalAttackIndex;
		if (npc.dwDropIndex != 0)
		{
			tmp.clear();
			tmp.push_back(ITEM);
			tmp.push_back(npc.dwDropIndex);
			tmp.push_back(npc.dwDropNumber);
			vecproduct.push_back(tmp);
		}
	}
	if (IsObjValid(vecproduct))
	{
		IME_ERROR("npc id %u item is unvalid index %u", npc.dwNPCId, npc.dwDropIndex);
		m_pCRole->SendErrorMsg(ERRNO_MSG_CSV_DATA, CMD_SC_TASK_COMBAT_RESULT);
		return;
	}

	if (index != preindex)
	{
		IME_ERROR("preview is not same with combat index %u, view %u", index, preindex);
		m_pCRole->SendErrorMsg(ERRNO_MSG_DUPLICATE_EQUIP, CMD_SC_TASK_COMBAT_RESULT);
		return;
	}
	
	if (result) //lose
	{
		m_PreviewCombatPacket.clear();
		std::vector<CombatResult> res;
		const std::vector< CHero* > hero = m_pCRole->GetvecHero();
		for (unsigned int i = 0; i < hero.size(); i++)
		{
			if (hero[i] == NULL)
				continue;
			CombatResult tmp;
			tmp.heropos = i;
			tmp.lv = hero[i]->GetwLevel();
			tmp.exp = hero[i]->GetdwExp();
			tmp.explimit = hero[i]->GetdwLevelLimit();
			tmp.newlv = hero[i]->GetwLevel();
			tmp.newexp = hero[i]->GetdwExp();
			tmp.newexplimit = hero[i]->GetdwLevelLimit();
			res.push_back(tmp);
		}
		m_pCRole->SendEffectCombatResult(result, res, 0, 0, 0, m_pCRole->GetwLevel(), m_pCRole->GetdwExp(), m_pCRole->GetwLevel(), m_pCRole->GetdwExp());
	}	
	else //win
	{
		if (m_mapTask.find(index) == m_mapTask.end())
		{
			TaskData d;
			d.PassTime = time(NULL);
			d.Number = 1;
			d.FlushTime = time(NULL);
			m_mapTask[index] = d;
		}
		else
		{
			m_mapTask[index].PassTime = time(NULL);
			m_mapTask[index].Number++;
		}

		std::vector< std::vector<uint32_t> > vecEffect;
		std::vector<uint32_t> effect;
		uint64_t lcir = m_pCRole->GetNewCirculateId();
		for (unsigned int i = 0; i < vecproduct.size(); i++)
		{
			GiveGameProduct(m_pCRole, vecproduct[i], effect, SOURCE_TASK, lcir);
			vecEffect.push_back(effect);
		}
		m_pCRole->SendObjEffect(vecEffect);

		m_PreviewCombatPacket.clear();
		m_pCRole->ChangeEnergy(-pConf->wEnergyConsume);

		uint32_t last_role_exp = m_pCRole->GetdwExp();
		uint16_t last_role_lv = m_pCRole->GetwLevel();
		m_pCRole->ChangeCoin(pConf->dwCoin, SOURCE_TASK, lcir);
		m_pCRole->AddExp(pConf->dwRoleExp);
		m_pCRole->Calculate(true);
		uint32_t new_role_exp = m_pCRole->GetdwExp();
		uint16_t new_role_lv = m_pCRole->GetwLevel();
		
		std::vector<CombatResult> res;
		const std::vector< CHero* > hero = m_pCRole->GetvecHero();
		for (unsigned int i = 0; i < hero.size(); i++)
		{
			if (hero[i] == NULL)
				continue;
			CombatResult tmp;
			tmp.heropos = i;
			tmp.lv = hero[i]->GetwLevel();
			tmp.exp = hero[i]->GetdwExp();
			tmp.explimit = hero[i]->GetdwLevelLimit();
			hero[i]->AddExp(pConf->dwHeroExp);
			hero[i]->Calculate();
			tmp.newlv = hero[i]->GetwLevel();
			tmp.newexp = hero[i]->GetdwExp();
			tmp.newexplimit = hero[i]->GetdwLevelLimit();
			m_pCRole->Calculate();
			res.push_back(tmp);
		}
		m_pCRole->HandlerHeroInfo();
		m_pCRole->SendEffectCombatResult(result, res, pConf->dwCoin, pConf->dwRoleExp, pConf->dwHeroExp, last_role_lv, last_role_exp, new_role_lv, new_role_exp);

	}

	WorldPacket info(CMD_SC_TASK_COMBAT_RESULT);
	info << (uint16_t) 0;
	info << result;
	m_pCRole->SendPacket(&info);
	
	return ;
}		/* -----  end of method CTask::HandlerCombatResult  ----- */

void
CTask::HandlerTaskInfo (uint32_t index)
{
	uint32_t now = time(NULL);
	WorldPacket info(CMD_SC_TASK_INFO);
	if (index == 0)
	{
		info << (uint32_t) m_mapTask.size();
		std::map<uint32_t, TaskData>::iterator it;
		for (it = m_mapTask.begin(); it != m_mapTask.end(); it++)
		{
			info << it->first;
			info << it->second.Number;
			const STC_CONF_AREA *pConf = CConfArea::Find(it->first);
			int cd = 0;
			if (pConf == NULL)
			{
				IME_ERROR("can not find index %u in this area csv", it->first);
			}
			else
			{
				cd = it->second.PassTime + pConf->dwCD - now;			
				cd = cd < 0 ? 0 : cd;
			}
			info << cd;
		}
		m_pCRole->SendPacket(&info);
	}
	else
	{
		std::map<uint32_t, TaskData>::iterator it;
		it = m_mapTask.find(index);
		if (it != m_mapTask.end())
		{
			info << (uint32_t) 1;
			info << it->first;
			info << it->second.Number;
			const STC_CONF_AREA *pConf = CConfArea::Find(index);
			int cd = 0;
			if (pConf == NULL)
			{
				IME_ERROR("can not find index %u in this area csv", index);
			}
			else
			{
				cd = it->second.PassTime + pConf->dwCD - now;			
				cd = cd < 0 ? 0 : cd;
			}
			info << cd;
		}
		m_pCRole->SendPacket(&info);
	}
	return ;
}		/* -----  end of method CTask::HandlerTaskInfo  ----- */

void
CTask::OnTimer5s ()
{
	uint32_t now = time(NULL);
	uint8_t IsUpdate = false;
	std::map<uint32_t, TaskData>::iterator it;
	for (it = m_mapTask.begin(); it != m_mapTask.end(); it++)
	{
		if (!CUtil::IsToday(it->second.PassTime))
		{
			it->second.FlushTime = now;
			it->second.Number = 0;
			IsUpdate = true;
		}
	}
	if (IsUpdate)
		HandlerTaskInfo();
	return ;
}		/* -----  end of method CTask::OnTimer5s  ----- */
