/*
 * =====================================================================================
 *
 *       Filename:  Item.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月22日 06时20分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "Item.h"
#include "DBCtrl.h"
#include "Role.h"
#include "CmdDefine.h"
#include "CommonConfig.h"

CItemBase *CreateItem(uint32_t dwObjId, uint16_t wType, uint32_t dwNum, uint32_t index)
{
	CItemBase *p = NULL;
	switch (wType)
	{
		case ITEM_WEAPON:
		case ITEM_ARMOR:
		case ITEM_SHOE:
		case ITEM_HEAD:
		case ITEM_WING:
		case ITEM_CLOAK:
			p = new(std::nothrow) CItemEquip();
			if (p == NULL) return p;
			break;
		case ITEM_CONSUME:
		case ITEM_COMBINE:
			p = new(std::nothrow) CItemMisc();
			if (p == NULL) return p;
			break;
		default:
			IME_ERROR("this type %u can not support index %u", wType, index);
			return NULL;
	}
	
	p->SetdwObjId(dwObjId);
	p->SetdwNum(dwNum);
	p->SetwType(wType);
	p->SetdwIndex(index);
	return p;
}

CItem::CItem():m_IsInit(false)
{
}

CItem::~CItem()
{
	for (std::map<uint32_t, CItemBase*>::iterator it = m_mapItem.begin(); it != m_mapItem.end(); it++)
	{
		delete it->second;
		it->second = NULL;
	}
}

int CItem::Init(CRole *pCRole)
{
	SetCRole(pCRole);
	if (!LoadData())
	{
		m_IsInit = false;
		IME_ERROR("load data fail");
		return -1;
	}
	m_IsInit = true;
	return 0;
}		/* -----  end of method CItem::Init  ----- */


bool CItem::LoadData ( )
{
	std::string temp;
	if (!CDBCtrl::GetUserItemPacketData(temp, m_pCRole->GetdwAccountId()))
	{
		IME_ERROR("get item data fail, user_id %u", m_pCRole->GetdwAccountId());
		return false;
	}
	ByteBuffer content;
	content.append(temp.data(), temp.size());
	if (DeSerilizeDB(content))
	{
		IME_ERROR("serilizeDB fail");
		return false;
	}
	return true;
}		/* -----  end of method CItem::LoadData  ----- */


int CItem::SaveData ()
{
	if (!m_IsInit)
		return -1;
	ByteBuffer byte;
	if (SerilizeDB(byte))
	{
		IME_ERROR("SerilizeDB fail");
		return -1;
	}
	std::string temp;
	temp.assign((const char *)byte.contents(), byte.size());
	CDBCtrl::SaveUserItemPacketData(temp, m_pCRole->GetdwAccountId());
	return 0;
}		/* -----  end of method CItem::SaveData  ----- */


int CItem::SerilizeDB ( ByteBuffer &byte)
{
	if (m_mapItem.size() == 0)
		return 0;
	byte << (uint32_t) 0;
	byte << (uint32_t) m_mapItem.size();
	std::map<uint32_t, CItemBase* >::iterator it;
	for (it = m_mapItem.begin(); it != m_mapItem.end(); it++)
	{
		byte << (it->second)->GetdwObjId();
		byte << (it->second)->GetdwNum();
		byte << (it->second)->GetwType();
		byte << (it->second)->GetdwIndex();
		ByteBuffer oneby;
		(it->second)->SerilizeDB(oneby);
		byte << (uint32_t)oneby.size();
		byte.append((const char *)oneby.contents(), oneby.size());
	}

	return 0;
}		/* -----  end of method CItem::SerilizeDB  ----- */

int CItem::DeSerilizeDB ( ByteBuffer &byte)
{
	if (byte.size() == 0)
		return 0;
	uint32_t item_number;
	uint32_t objid;
	uint32_t number;
	uint32_t version;
	uint16_t type;
	uint32_t index;
	byte >> version;
	
	if (version == 0)
	{
		byte >> item_number;
		for (unsigned int i = 0; i < item_number; i++)
		{
			byte >> objid;
			byte >> number;
			byte >> type;
			byte >> index;

			ByteBuffer oneby;
			std::string temp;
			uint32_t len = 0;
			byte >> len;
			byte.read(temp, len);
			oneby.append(temp.c_str(), temp.size());
			CItemBase *p = NULL;

			CREATE_ONE_ITEM(objid, type, number, index, oneby, p); 

//			Item_t tempItem = {objid, number};
			m_mapItem[objid] = p;
			IME_DEBUG("item objid %u, number %u", objid, number);
		}
	}
	else
	{
		IME_ERROR("server version it too old than DB, item blob data version %u", version);
		return -1;
	}
	
	// used to switch data from one version to other version	
	if (version == 0)
	{

	}

	return 0;
}		/* -----  end of method CItem::DeSerilizeDB  ----- */

void
CItem::HandlerItemInfo (uint32_t objid)
{
	WorldPacket info(CMD_SC_ROLE_ITEM_PACKET_INFO);
	if (objid == 0)
	{
		uint32_t number = m_mapItem.size();
		info << number;
		std::map<uint32_t, CItemBase* >::iterator it;
		for(it = m_mapItem.begin(); it != m_mapItem.end(); it++)
		{
			info << (it->second)->GetdwObjId();
			info << (it->second)->GetdwNum();
			info << (it->second)->GetwType();
			info << (it->second)->GetdwIndex();
			it->second->PkgData(info);
//			IME_DEBUG("pieces index %u number %u", (it->second)->GetdwObjId(), (it->second)->GetdwNum());
		}
	}
	else
	{
		info << (uint32_t)1;
		std::map<uint32_t, CItemBase* >::iterator it = m_mapItem.find(objid);
		if (it != m_mapItem.end())
		{
			info << (it->second)->GetdwObjId();
			info << (it->second)->GetdwNum();
			info << (it->second)->GetwType();
			info << (it->second)->GetdwIndex();
			it->second->PkgData(info);
//			IME_DEBUG("pieces index %u number %u", (it->second)->GetdwObjId(), (it->second)->GetdwNum());
		}
		else
		{
			IME_ERROR("can not find objid %u", objid);
			return;
		}
	}
	m_pCRole->SendPacket(&info);	
	return ;
}		/* -----  end of method CItem::HandlerItemInfo  ----- */

int CItem::AddItem(uint32_t index, uint32_t &objid, int source, uint64_t cir, uint32_t number)
{
//	Item_t CellItem = {objid, number};	
	objid = 0;
	objid = index;
	if (number == 0)
	{
		IME_LOG("add zero item objid %u, source %u", objid, source);
		return 0;
	}
	if (m_mapItem.find(objid) != m_mapItem.end())
	{
		m_mapItem[objid]->SetdwNum(m_mapItem[objid]->GetdwNum() + number);
	}
	else
	{
//		if (!CDBCtrl::InsertItemUser(objid, m_pCRole->GetdwAccountId()))
//		{
//			IME_ERROR("insert itemuser table fail objid %u, userid %u", objid, m_pCRole->GetdwAccountId());
//			return -1;
//		}
		
		STC_CONF_ITEM *pConf = CConfItem::Find(index);
		if (pConf == NULL)
		{
			IME_ERROR("can not find csv index %u", index);
			return -1;
		}
		CItemBase *p = NULL;
		ByteBuffer by;
		objid = index;
		CREATE_ONE_ITEM(objid, pConf->wType, number, index, by, p);

		m_mapItem[objid] = p;
		return 0;
	}
	IME_CHAR_LOG(m_pCRole->GetdwAccountId(),"RESOURCE","type=item|opt=add|character=%u|index=%u|number=%u|source=%d|circulateid=%llu", m_pCRole->GetdwAccountId(), objid, number, source, (unsigned long long)cir);
	return 0;
}

int CItem::DelItem(uint32_t objid, int source, uint64_t cir, uint32_t number)
{
	if (number == 0)
	{
		IME_WARN("del zero item objid %u, source %u", objid, source);
		return 0;
	}
	std::map<uint32_t, CItemBase* >::iterator it;
	it = m_mapItem.find(objid);
	if (it != m_mapItem.end())
	{
		if (m_mapItem[objid]->GetdwNum() < number)
		{
			IME_ERROR("its number [%u] small than request [%u]", m_mapItem[objid]->GetdwNum(), number);
			return -1;
		}
		else if (m_mapItem[objid]->GetdwNum() == number)
		{
//			if (!CDBCtrl::DeleteItemUser(objid, m_pCRole->GetdwAccountId()))
//			{
//				IME_ERROR("delete itemuser table fail objid %u, userid %u", objid, m_pCRole->GetdwAccountId());
//				IME_CHAR_LOG("resource [status=success,res=pieces,opt=del,character=%u,index=%u,number=%u,reason=delete item user data fail,source=%d]", m_pCRole->GetdwAccountId(), objid, number, source);
//				return -1;
//			}
			delete it->second;
			it->second = NULL;
			m_mapItem.erase(it);
		}
		else
		{
			m_mapItem[objid]->SetdwNum( m_mapItem[objid]->GetdwNum() - number);
		}
		IME_CHAR_LOG(m_pCRole->GetdwAccountId(), "RESOURCE", "type=item|opt=del|character=%u|index=%u|number=%u|source=%d|circulateid=%llu", m_pCRole->GetdwAccountId(), objid, number, source, (unsigned long long)cir);
		return 0;
	}
	else
	{
		IME_ERROR("it is not in packet %u", objid);
		return -1;
	}
}

void CItem::ItemUpdate(uint32_t objid, uint8_t action, uint32_t number)
{
	WorldPacket info(CMD_SC_ROLE_ITEM_PACKET_CHANGE);
	if (action == ADD)
	{
		info << (uint32_t)1;
		info << (uint8_t)ADD;
		info << objid;
		info << number;
		std::map<uint32_t, CItemBase* >::iterator it;
		it = m_mapItem.find(objid);
		if (it != m_mapItem.end())
		{
			info << it->second->GetwType();
			info << it->second->GetdwIndex();
			it->second->PkgData(info);
		}
		else
		{
			IME_ERROR("can not find item objid %u", objid);
			return;
		}
	}
	else if (action == DEL)
	{
		info << (uint32_t)1;
		info << (uint8_t)DEL;
		info << objid;
		info << number;
	}
	else
	{
		IME_ERROR("unknow action %u", action);
		return;
	}
	m_pCRole->SendPacket(&info);
}

int CItem::JudgeItemNumber(uint32_t objid, uint32_t number)
{
	std::map<uint32_t, CItemBase* >::iterator it;
	it = m_mapItem.find(objid);
	if (it != m_mapItem.end())
	{
		if (m_mapItem[objid]->GetdwNum() < number)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		IME_ERROR("it is not in packet %u", objid);
		return -1;
	}
}

CItemBase::CItemBase():m_dwObjId(0),m_dwNum(0),m_wType(0)
{

}

CItemBase::~CItemBase()
{

}

int CItemBase::Init(ByteBuffer &by)
{
	return 0;
}

void CItemBase::SerilizeDB(ByteBuffer &by)
{
}

void CItemBase::PkgData(ByteBuffer &by)
{
}

CItemEquip::CItemEquip()
{

}

CItemEquip::~CItemEquip()
{

}

int
CItemEquip::Init ( ByteBuffer &by )
{
	by >> m_wLevel;

	if (LoadConf())
	{
		IME_ERROR("load conf fail index %u", GetdwIndex());
		return -1;
	}

	if (Calculate())
	{
		IME_ERROR("calculate fail index %u", GetdwIndex());
		return -1;
	}

	return 0;
}		/* -----  end of method CItemEquip::Init  ----- */


void
CItemEquip::SerilizeDB (ByteBuffer &by)
{
	by << m_wLevel;
	return ;
}		/* -----  end of method CItemEquip::SerilizeDB  ----- */


void
CItemEquip::PkgData (ByteBuffer &by)
{
	by << m_wLevel;
	by << m_wStarLevel;
	by << m_wUseLevelLimit;
	by << m_byProfessionLimit;
	by << m_dwAttack;
	by << m_dwAttackGrow;
	by << m_dwDefence;
	by << m_dwDefenceGrow;
	by << m_dwStrength;
	by << m_dwStrengthGrow;
	by << m_dwHeal;
	by << m_dwHealGrow;
	by << m_dwPowerRecover;
	by << m_dwPowerRecoverGrow;
	by << m_dwAttackSpeed;
	by << m_dwAttackTime;
	by << m_dwDodge;
	by << m_dwCrit;
	by << m_dwCritPower;
	by << m_dwHit;
	by << m_dwSuckBlood;
	return ;
}		/* -----  end of method CItemEquip::PkgData  ----- */

int
CItemEquip::LoadConf ()
{
	STC_CONF_ITEM *pConf = CConfItem::Find(GetdwIndex());
	if (pConf == NULL)
	{
		IME_ERROR("can not find item csv index %u", GetdwIndex());
		return -1;
	}

	m_wUseLevelLimit = pConf->dwUseLevel;
	m_wStarLevel = pConf->wStar;
	m_byProfessionLimit = pConf->wProfession;
	m_dwAttackInit = pConf->dwInitAttack;
	m_dwAttackGrow = pConf->dwAttackGrow;
	m_dwDefenceInit = pConf->dwInitDefence;
	m_dwDefenceGrow = pConf->dwDefenceGrow;
	m_dwStrengthInit = pConf->dwInitStrength;
	m_dwStrengthGrow = pConf->dwStrengthGrow;
	m_dwHealInit = pConf->dwInitHeal;
	m_dwHealGrow = pConf->dwHealGrow;
	m_dwPowerRecoverInit = pConf->dwInitPowerRecover;
	m_dwPowerRecoverGrow = pConf->dwPowerRecoverGrow;
	m_dwAttackSpeed = pConf->dwAttackSpeed;
	m_dwAttackTime = pConf->dwAttackTime;
	m_dwDodge = pConf->dwDodge;
	m_dwCrit = pConf->dwCritPro;
	m_dwCritPower = pConf->dwCritPower;
	m_dwHit = pConf->dwHit;
	m_dwSuckBlood = pConf->dwSuckBlood;
	return 0;
}		/* -----  end of method CItemEquip::LoadConf  ----- */

int
CItemEquip::Calculate ()
{
	SetdwAttack(m_dwAttackInit + m_dwAttackGrow * m_wLevel);
	SetdwDefence(m_dwDefenceInit + m_dwDefenceGrow * m_wLevel);
	SetdwStrength(m_dwStrengthInit + m_dwStrengthGrow * m_wLevel);
	SetdwHeal(m_dwHealInit + m_dwHealGrow * m_wLevel);
	SetdwPowerRecoverGrow(m_dwPowerRecoverInit + m_dwPowerRecoverGrow * m_wLevel);
	return 0;
}		/* -----  end of method CItemEquip::Calculate  ----- */

CItemMisc::CItemMisc()
{

}

CItemMisc::~CItemMisc()
{

}
