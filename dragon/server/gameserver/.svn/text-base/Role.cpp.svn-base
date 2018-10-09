#include "Role.h"
#include "DatabaseMysql.h"
#include "PlayerSession.h"
#include "ShardingDB.h"
#include "CmdDefine.h"
#include "ErrorMsg.h"
#include "EnumDefines.h"
#include "GmCmdPro.h"
//#include "LuaScript.h"
//#include "LuaState.h"
//#include "LuaCtrl.h"
#include "ConfigData.h"
#include <cmath>
#include <new>
#include "NameChecker.h"
#include "World.h"
#include "GlobalConfig.h"
#include "CmdInnerDefine.h"
#include "Log.h"
#include "CenterDBCtrl.h"
#include "Notice.h"
#include "EnumDefines.h"
#include "Timer.h"
#include "Other.h"
#include "DBCtrl.h"
#include "GlobalConfig.h"
#include "Notice.h"
#include "RoleBase.h"
#include "Item.h"
#include <algorithm>
#include "Hero.h"
#include "Task.h"

#define ERROR_NEW_TEST(t, name) \
    if (t == NULL)\
    {\
    IME_LOG("NEW A OBJECT FAIL %s", name);\
    abort();\
    }
#define ERROR_INIT_TEST(t, name) \
    if (t == NULL)\
    {\
    IME_LOG("A OBJECT INIT FAIL %s", name);\
    return false;\
    }
#define ERROR_LOAD_TEST(t, name) \
    if (t)\
    {\
    IME_LOG("A OBJECT[%s] LOAD DATA FAIL", name);\
	return false;\
    }
#define ERROR_SAVE_TEST(t, name) \
    if (t)\
    {\
    IME_LOG("A OBJECT[%s] SAVE DATA FAIL", name);\
    }
#define SAFE_DELETE_OBJECT(t) \
	if (t)\
	{\
		delete t;\
		t = NULL;\
	}

//extern CLuaState g_luaState;
extern CShardingDB WorldShardingDB;

CRole::CRole(CHandlerPlayersession * pSession)
:m_pSession(pSession)
{

	m_bIsInitOK = false;
	m_dwUserOnlineTime = 0;
	m_byFirstLogin = 0;
	m_loginauto = 0;
	m_dwGmFlushTime = 0;
	m_vecTime.resize(TIME_MAX);

	m_clsItemPacket = NULL;
	m_lCirculateId = 0;
	m_dwOrderId = 0;
	m_byNoSendLoginData = 0;
	m_vecHero.resize(POS_PRO_MAX);
	m_vecEquip.resize(POS_PRO_MAX);
	m_vecHeroProperty.resize(POS_PRO_MAX);
	m_clsTask = NULL;
	m_dwTotalCombatValue = 0;
}

CRole::~CRole()
{
	IME_LOG("RELEASE ROLE[UserId=%u]", GetdwAccountId());
	SAFE_DELETE_OBJECT(m_clsItemPacket);
	for (unsigned int i = 0; i < m_vecHero.size(); i++)
	{
		SAFE_DELETE_OBJECT(m_vecHero[i]);
	}
	SAFE_DELETE_OBJECT(m_clsTask);
}

bool CRole::Init(uint32 dwAccountId, const std::string & strAccount)
{
	//初始化角色数据
	//这两个数据不会变
//	SetdwAccountId(dwAccountId);
//	SetstrAccount(strAccount);
	
	INIT_PROCESS_TIMER;
	PROCESS_TIMER_START;

	if (dwAccountId == 0)
	{
		IME_ERROR("userid is 0");
		return false;
	}

	int is_ok = LoadRole(dwAccountId);
	if (is_ok == E_SQL_RESULT_NO_ROLE)// new role, create him
	{
		int ret = CDBCtrl::NewUserData(dwAccountId, strAccount);
//		int tmp_is_ok = LoadRole();
//		if (tmp_is_ok != E_SQL_RESULT_SUCC)
//		{
//			IME_ERROR("ROLE INIT ERROR, DB GET NULL");
//			return false;
//		}
		if (ret == 0)
		{
			IME_ERROR("ROLE INIT ERROR, DB OPT FAIL");
		}

		RoleBase data;
		data.dwAccountId = dwAccountId;
		data.strAccount = strAccount;
		data.strUserName = CUtil::Uint32ToString(dwAccountId);
		data.wLevel = 0;
		data.dwExp = 0;
		data.dwVipLv = 0;
		data.dwVipTotalExp = 0;
		data.lDollar = 0;
		data.lCoin = 0;
		data.dwEnergy = 0;
		data.dwEnergyTime = 0;
		data.dwVipEndTime = 0;
		data.byStatus = 0;
		data.dwTaskPosition = 0;
		data.strToken = "";
		data.dwGameFlow = 0;
		sWorld->AddRoleBase(data);
	}
	else if (is_ok == E_SQL_RESULT_SQL_ERROR)
	{
		IME_ERROR("Role Init sql error");
		return false;
	}
	if (!CRoleBase::Init(dwAccountId))
	{
		IME_ERROR("role base init fail");
		return false;
	}

	PROCESS_TIMER_END("rolebase init");

	if (OtherDataGet())
	{
		IME_ERROR("get other data fail");
		return false;
	}
	
	if (LoadHero())
	{
		IME_ERROR("load hero data fail");
		return false;
	}

	if (LoadEquip())
	{
		IME_ERROR("load equip data fail");
		return false;
	}
	PROCESS_TIMER_END("load data");

//	IME_DEBUG("init a role");
		
	if (!CDBCtrl::GetShopOrderId(GetdwAccountId(), m_dwOrderId))
	{
		IME_ERROR("user %u give order id fail", GetdwAccountId());
		return false;
	}

	int ret = 0;

	m_clsItemPacket = new(std::nothrow) CItem();
	ERROR_NEW_TEST(m_clsItemPacket, "ItemPacket");
	
	ret = m_clsItemPacket->Init(this);
	ERROR_LOAD_TEST(ret, "ItemPacket");

	PROCESS_TIMER_END("new and init item class");

	m_clsTask = new(std::nothrow) CTask();
	ERROR_NEW_TEST(m_clsTask, "Task");

	ret = m_clsTask->Init(this);
	ERROR_LOAD_TEST(ret, "Task");
	PROCESS_TIMER_END("new and init task class");

	//新账号初始化
	if (GetwLevel() == 0)
	{
	}
	else
	{
		m_dwGmFlushTime = CenterDBCtrl::HandlerGmCommandRole(this, m_dwGmFlushTime);
		Calculate();

		OnTimer1s();
		OnTimer5s();
	}

	m_bIsInitOK = true;
	return true;
}

void CRole::SendLoginData()
{
	IME_LOG("Send Login Data[UserId=%u]", GetdwAccountId());

	SendProUpdate();
	GlobalConfig::SendData(this);	
	sWorld->GetCAnnouncement()->HandlerInfo(this);
	HandlerWorldBroadCastInfo();
	m_clsItemPacket->HandlerItemInfo();
	HandlerHeroInfo();
	HandlerEquipInfo();
	m_clsTask->HandlerTaskInfo();
	//todo
}

int CRole::LoadRole(uint32_t dwAccountId)
{
	//操作太危险了!!!
	//先查看有没有角色
	//E_SQL_RESULT_NO_ROLE,			//新角色
//	bool bIsNew = CDBCtrl::IsNewRole(m_strAccount);
	bool bIsNew = CDBCtrl::IsNewRole(dwAccountId);
	if (bIsNew)
	{
		return E_SQL_RESULT_NO_ROLE;
	}
	return E_SQL_RESULT_SUCC;
}

//客户端GM
void CRole::OnGMCmd(std::string & strContent)
{
	CGmCmdPro::PraseCmd(this,strContent);
}

//////////////////////////////////////
void CRole::OnTimer1s()
{
//	uint32_t now = time(NULL);
	if (IsInitRoleInfo())
	{
	}
}

void CRole::OnTimer5s()
{
	if (IsInitRoleInfo())
	{
		uint32_t now = time(NULL);
		if (GetdwEnergyTime() + GlobalConfig::EnergyRate <= now)                                           
		{                                                                                    
//			IME_DEBUG("now %u, energy %u, rate %u", now, GetdwEnergyTime(), GlobalConfig::EnergyRate);     
			ChangeEnergy(1);                                                                 
			SetdwEnergyTime(GetdwEnergyTime() + GlobalConfig::EnergyRate);
			SendProUpdate();                                                                 
		}                                                                                    
		uint32_t vipend = GetdwVipEndTime();
		if (vipend != 0 && vipend <= now)
		{
			uint32_t lv = 0;
			uint32_t exp = 0;
			CConfVip::GetResult(INIT_VIP_LEVEL, GetdwVipTotalExp(), lv, exp);
			lv = lv > (uint32_t)GlobalConfig::FreeMaxVipLevel ? GlobalConfig::FreeMaxVipLevel : lv;
			if (lv > GetdwVipLv())
				SetdwVipLv(lv);
			SetdwVipEndTime(0);
			SendProUpdate();
		}
		m_clsTask->OnTimer5s();
	}
}

void CRole::OnTimer3min()
{
	// save data
	SaveAllData();
	if (IsInitRoleInfo())
	{
		m_dwGmFlushTime = CenterDBCtrl::HandlerGmCommandRole(this, m_dwGmFlushTime);
	}
}

void CRole::statisticsRole()
{
	uint8_t gm = IS_GM(GetbyStatus());
	CenterDBCtrl::UpdateRoleGmAuth(GetdwAccountId(), gm);
}

void CRole::SaveAllData()
{
	if (!m_bIsInitOK)
		return ;
	CRoleBase::SaveData();
	OtherDataSave();
	m_clsItemPacket->SaveData();
	SaveHero();
	SaveEquip();
	m_clsTask->SaveData();
}

void CRole::Offline()
{
	IME_LOG("PLAYER OFFLINE[UserId=%u]", GetdwAccountId());
	if (!m_bIsInitOK)
		return ;
	// 用户离开游戏
	sWorld->DelUserAuth(GetdwAccountId());

	// 保存所有用户数据
	SaveAllData();

	// 最近一次离开游戏时间记录
	if (m_dwUserOnlineTime != 0)
	{
		uint32_t last_login_time, last_logout_time, cur_login_time, login_day;
		std::string last_login_ip;
		if (CDBCtrl::GetUserLoginData(GetdwAccountId(), last_login_time, last_logout_time, cur_login_time, login_day, last_login_ip))
		{
			last_logout_time = time(NULL);
			cur_login_time = time(NULL) - m_dwUserOnlineTime;
			CDBCtrl::SaveUserLoginData(GetdwAccountId(), last_login_time, last_logout_time, cur_login_time, login_day, last_login_ip);
		}
	}
	CenterDBCtrl::InsertOrUpdateRoleInfo(GetdwAccountId(), GetstrUserName(), (uint8_t)IS_GM(GetbyStatus()), (uint8_t)IS_LIMIT_LOGIN(GetbyStatus()), GetdwGameFlow(), GetwLevel(), GetlCoin(), GetlDollar(), GetdwTaskPosition() , 0, GetdwVipLv(), GetdwVipTotalExp(), 0, GetdwEnergy());
	CenterDBCtrl::InsertLogoutInfo(m_loginauto);
	//上次登录时间

}

void CRole::Online()
{
//	INIT_PROCESS_TIMER;
//	PROCESS_TIMER_START;
	if (!m_bIsInitOK)
		return ;
	// 用户登录游戏
	sWorld->AddUserAuth(GetdwAccountId(), GetSession());

	// 最近一次登录游戏时间
	uint32_t last_login_time, last_logout_time, cur_login_time, login_day;
	std::string last_login_ip;
	if (CDBCtrl::GetUserLoginData(GetdwAccountId(), last_login_time, last_logout_time, cur_login_time, login_day, last_login_ip))
	{
		m_dwUserOnlineTime = time(NULL);
		if (last_login_time == 0)
		{
			login_day = 1;
			m_byFirstLogin = 1;
		}
		else
		{
			uint32_t lastt = CUtil::GetDateTime(last_login_time + 24 * 3600);
			uint32_t nextt = CUtil::GetDateTime(time(NULL));
//			IME_ERROR("lastt %u, nextt %u", lastt, nextt);

			if (lastt == nextt)
			{
				login_day += 1;
				m_byFirstLogin = 1;
			}
			else if (lastt < nextt)
			{
				m_byFirstLogin = 1;
				login_day = 0;
			}
			else
			{
				// now login	
				m_byFirstLogin = 0;
			}
		}
		last_login_time = time(NULL);
		last_logout_time = 0;
		last_login_ip = m_pSession->GetPlayersession()->GetRemoteIP();
		CDBCtrl::SaveUserLoginData(GetdwAccountId(), last_login_time, last_logout_time, cur_login_time, login_day, last_login_ip);
	}

	// 用户登录
	if (!GetbyNoSendLoginData())
		SendLoginData();

	CenterDBCtrl::InsertOrUpdateRoleInfo(GetdwAccountId(), GetstrUserName(), (uint8_t)IsGM(), 0, GetdwGameFlow(), GetwLevel(), GetlCoin(), GetlDollar(), GetdwTaskPosition() , 0, GetdwVipLv(), GetdwVipTotalExp(), 0, GetdwEnergy());
	CenterDBCtrl::UpdateRoleLastLoginTime(GetdwAccountId());
	m_loginauto = CenterDBCtrl::InsertLoginInfo(GetdwAccountId(), m_pSession->GetPlayersession()->GetRemoteIP(), m_pSession->GetLoginDevice(), m_pSession->GetLoginDeviceType());

	if (m_byFirstLogin)
	{
	}

	//最后时候再发送验证成功，保证所有数据先到达客户端
//	if (GetwLevel())
//	{
	      m_pSession->SendAuthInfo(ERRNO_MSG_SUCC);
//	}
	IME_LOG("user online useid %u", GetdwAccountId());
//	PROCESS_TIMER_END("calculate login data");
}

void CRole::TestScriptByName(const std::string & strName)
{
//	CLuaScript * pLuaScript = CLuaCtrl::FindScript("Role.lua");
//	if (!pLuaScript)
//		return ;
//	if (!pLuaScript->Call(strName.c_str(),"e","CRole",this))
//	{
//		IME_LOG("Role Script Func Name:%s call failed",strName.c_str());
//	}
}

////////////////////////////发送系列////////////////////////////////////////////
void CRole::SendPacket(WorldPacket * packet)
{
	m_pSession->SendPacket(packet);
}

void CRole::SendMsgStr(const std::string& Msg)
{
        WorldPacket data(CMD_SC_MSG_STR);
        data << Msg;
        SendPacket(&data);
}

void CRole::SendErrorMsg(uint16 ErrorMsgNum, uint16 wCmd)
{
	// 命令号存在，则返回包用该命令号，否则用错误码专用命令号
	uint16 wCurCmd;
	if (wCmd)
	{
		wCurCmd = wCmd;
	}
	else
	{
		wCurCmd = CMD_SC_ERROR_MSG;
	}
	WorldPacket pkg(wCurCmd);
	pkg << ErrorMsgNum;
	SendPacket(&pkg);
}

void CRole::SendProUpdate()
{
	WorldPacket data(CMD_SC_ROLE_PROPERTY);
//	IME_DEBUG("data size %u", (uint32_t)data.size());
	data << GetdwAccountId();
	data << GetstrAccount();
	data << GetstrUserName();
	data << GetwLevel();
	data << GetdwExp();
	data << GetdwVipLv();
	data << GetdwVipTotalExp();
	data << GetlDollar();
	data << GetlCoin();
	data << GetdwEnergy();
	data << GetbyStatus();
	data << GetdwTaskPosition();
	data << GetstrToken();

	int32_t next_point_time;
	int32_t all_time;
	
	uint32_t now = time(NULL);
	next_point_time = (GetdwEnergyTime() + GlobalConfig::EnergyRate) - now;	
	if (next_point_time < 0)
		next_point_time = 0;

	uint32_t energyLimit = 0;
	if (GetwLevel() != 0)
	{
		STC_CONF_ROLE *pConf = CConfRole::Find(GetwLevel());
		if (!pConf)
		{
			IME_ERROR("can not find role exp csv lv %u", GetwLevel());
		}
		else
		{
			energyLimit = pConf->dwEnergyLimit;
		}
	}

	int need = energyLimit - GetdwEnergy();
	if (need < 0 )
	{
		need = 0;
		next_point_time = 0;
	}
	all_time = (GetdwEnergyTime() + GlobalConfig::EnergyRate * need) - now;
	if (all_time < 0)
		all_time = 0;
	data << next_point_time;
   	data << all_time;	
	data << CConfRole::GetMaxExpIntervalLv(GetwLevel());


	if (data.size() > 1)
	{
		SendPacket(&data);
	}
}

void CRole::SendErrorStr(const std::string& strMsg)
{
	WorldPacket pkg(CMD_SC_ERROR_STR);
	pkg << strMsg;
	SendPacket(&pkg);
}

int CRole::Calculate(bool IsUpdate)
{
	if (CRoleBase::Calculate())
		return -1;

	m_dwTotalCombatValue = 0;
	for (unsigned int i = 0; i < m_vecHero.size(); i++)
	{
		if (m_vecHero[i] == NULL)
			continue;
		
		m_vecHeroProperty[i].dwSelfAttack = m_vecHero[i]->GetdwAttack();
		m_vecHeroProperty[i].dwSelfDefence = m_vecHero[i]->GetdwDefence();
		m_vecHeroProperty[i].dwSelfStrength = m_vecHero[i]->GetdwStrength();
		m_vecHeroProperty[i].dwSelfHeal = m_vecHero[i]->GetdwHeal();
		m_vecHeroProperty[i].dwSelfPowerRecover = m_vecHero[i]->GetdwPowerRecover();
		m_vecHeroProperty[i].dwSelfAttackSpeed = m_vecHero[i]->GetdwAttackSpeed();
		m_vecHeroProperty[i].dwSelfAttackTime = m_vecHero[i]->GetdwAttackTime();
		m_vecHeroProperty[i].dwSelfDodge = m_vecHero[i]->GetdwDodge();
		m_vecHeroProperty[i].dwSelfCrit = m_vecHero[i]->GetdwCrit();
		m_vecHeroProperty[i].dwSelfCritPower = m_vecHero[i]->GetdwCritPower();
		m_vecHeroProperty[i].dwSelfHit = m_vecHero[i]->GetdwHit();
		m_vecHeroProperty[i].dwSelfSuckBlood = m_vecHero[i]->GetdwSuckBlood();

		m_vecHeroProperty[i].dwEquipAttack = 0;
		m_vecHeroProperty[i].dwEquipDefence = 0;
		m_vecHeroProperty[i].dwEquipStrength = 0;
		m_vecHeroProperty[i].dwEquipHeal = 0;
		m_vecHeroProperty[i].dwEquipPowerRecover = 0;
		m_vecHeroProperty[i].dwEquipAttackSpeed = 0;
		m_vecHeroProperty[i].dwEquipAttackTime = 0;
		m_vecHeroProperty[i].dwEquipDodge = 0;
		m_vecHeroProperty[i].dwEquipCrit = 0;
		m_vecHeroProperty[i].dwEquipCritPower = 0;
		m_vecHeroProperty[i].dwEquipHit = 0;
		m_vecHeroProperty[i].dwEquipSuckBlood = 0;

		for (unsigned int j = 0; j < m_vecEquip[i].size(); j++)
		{
			if (j == POS_EQUIP_SKILL)
				continue;

			CItemBase *q = GetclsItemPacket()->GetItem(m_vecEquip[i][j]);
			int arrtype[] = {ITEM_WEAPON, ITEM_ARMOR, ITEM_SHOE, ITEM_HEAD, ITEM_WING, ITEM_CLOAK};
			if (q == NULL || std::find(arrtype, arrtype + sizeof(arrtype) / sizeof(int), (int)q->GetwType()) == arrtype + sizeof(arrtype) / sizeof(int) ) 
			{
				IME_ERROR("can not find equip item objid %u or type is unvalid %u", m_vecEquip[i][j], q->GetwType());
				return -1;
			}
			CItemEquip *p = (CItemEquip *)q;

			m_vecHeroProperty[i].dwEquipAttack += p->GetdwAttack();
			m_vecHeroProperty[i].dwEquipDefence += p->GetdwDefence();
			m_vecHeroProperty[i].dwEquipStrength += p->GetdwStrength();
			m_vecHeroProperty[i].dwEquipHeal += p->GetdwHeal();
			m_vecHeroProperty[i].dwEquipPowerRecover += p->GetdwPowerRecover();
			m_vecHeroProperty[i].dwEquipAttackSpeed += p->GetdwAttackSpeed();
			m_vecHeroProperty[i].dwEquipAttackTime += p->GetdwAttackTime();
			m_vecHeroProperty[i].dwEquipDodge += p->GetdwDodge();
			m_vecHeroProperty[i].dwEquipCrit += p->GetdwCrit();
			m_vecHeroProperty[i].dwEquipCritPower += p->GetdwCritPower();
			m_vecHeroProperty[i].dwEquipHit += p->GetdwHit();
			m_vecHeroProperty[i].dwEquipSuckBlood += p->GetdwSuckBlood();
		}

		m_vecHeroProperty[i].dwCombatValue =  CALCULATE_HERO_COMBAT_VALUE(m_vecHeroProperty[i]);
		m_dwTotalCombatValue += m_vecHeroProperty[i].dwCombatValue;
	}

	if (IsUpdate)
	{
		SendProUpdate();
		HandlerEquipInfo();
	}
	return 0;
}

void CRole::SendEnergyNotEnough(uint16 wCmd)
{
	WorldPacket info(wCmd);
	info << (uint16) ERRNO_MSG_NOT_ENOUGH_ENERGY;
	int32_t next_point_time;
	int32_t all_time;
	
	uint32_t now = time(NULL);
	next_point_time = (GetdwEnergyTime() + GlobalConfig::EnergyRate) - now;	
	if (next_point_time < 0)
		next_point_time = 0;

	STC_CONF_ROLE *pConf = CConfRole::Find(GetwLevel());
	if (!pConf)
	{
		IME_ERROR("can not find role exp csv lv %u", GetwLevel());
		return;
	}

	int need = pConf->dwEnergyLimit - GetdwEnergy();
	if (need < 0 ) need = 0;
	all_time = (GetdwEnergyTime() + GlobalConfig::EnergyRate * need) - now;
	if (all_time < 0)
		all_time = 0;
	info << next_point_time;
   	info << all_time;	
	SendPacket(&info);
}

bool CRole::IsInitRoleInfo()
{
	return GetwLevel();
}	

void CRole::HandlerInitRole(WorldPacket &pkg)
{
	std::string username;
	pkg >> username;
	
	PACKET_REMAIN_CHECK(pkg, CMD_SC_INIT_ROLE_RESULT);
	CNameChecker::ReplaceString(username);	
	if (sWorld->IsExists(username))
	{
		IME_ERROR("user name already have been chosen name %s", username.c_str());
		SendErrorMsg(ERRNO_MSG_USER_NAME_ALREADY_USE, CMD_SC_INIT_ROLE_RESULT);
		return;
	}
	
	STC_CONF_ROLE *pConf = CConfRole::Find(1);
	if (!pConf)
	{
		IME_ERROR("can not find role config csv lv %u", GetwLevel());
		SendErrorMsg(ERRNO_MSG_CSV_LOAD, CMD_SC_INIT_ROLE_RESULT);
		return;
	}

	SetdwExp(0);
	SetwLevel(1);
	SetlCoin(GlobalConfig::InitCoin);
	SetlDollar(GlobalConfig::InitDollar);

	SetstrUserName(username);
	sWorld->InsertUserName(username);

	if (Calculate(false))
	{
		IME_ERROR("calculate fail");
		SendErrorMsg(ERRNO_MSG_CALCULATE, CMD_SC_INIT_ROLE_RESULT);
		return;
	}

	SetdwEnergyTime(time(NULL));
	SetdwEnergy(pConf->dwEnergyLimit);
	SendProUpdate();

//	m_vecHero[0] = new(std::nothrow) CHero();
//	if (m_vecHero[0] == NULL)
//	{
//		IME_ERROR("new objid fail hero");
//		SendErrorMsg(ERRNO_MSG_CREATE_HERO, CMD_SC_INIT_ROLE_RESULT);
//		return;
//	}
//	if (m_vecHero[0]->Create(this, FIRST_HERO))
//	{
//		IME_ERROR("init hero fail userid %u", GetdwAccountId());
//		SendErrorMsg(ERRNO_MSG_CREATE_HERO, CMD_SC_INIT_ROLE_RESULT);
//		return;
//	}
//
//	HandlerHeroInfo();	
	if (HeroCome(POS_PRO_SOLDIER))
	{
		IME_ERROR("hero add fail userid %u", GetdwAccountId());
		SendErrorMsg(ERRNO_MSG_CREATE_HERO, CMD_SC_INIT_ROLE_RESULT);
	}

	WorldPacket info2(CMD_SC_INIT_ROLE_RESULT);
	info2 << (uint16_t) 0;
	SendPacket(&info2);

	m_dwGmFlushTime = CenterDBCtrl::HandlerGmCommandRole(this, m_dwGmFlushTime);

	SetbyStatus(SET_YES_GM(GetbyStatus()));
	return;
}

void CRole::HandlerWorldBroadCastInfo()
{
//	WorldPacket info(CMD_SC_WORLD_BROADCAST_INFO);
//	
//	PkgWorldBroadCastInfo(0, 0, "", info);	
//	SendPacket(&info);
	sWorld->HandlerWorldChatInfo(this);
	sWorld->GetCNotice()->HandlerBroadCast(this);
}

void CRole::PkgWorldBroadCastInfo(uint8_t choose, std::string content, WorldPacket &info)
{
//	uint32_t now = time(NULL);
//	int64_t cd = (int64_t)(m_dwWorldBroadTime + GlobalConfig::WorldBroadCD) - now;	
//	cd = cd < 0 ? 0 : cd;
//	info << (uint32_t)cd;
//	info << cmd;
	info << choose;
	info << GetdwAccountId();
	info << GetstrUserName();
	info << content;
	info << GetdwVipLv();

	SWorldChat tmp;
	tmp.choose = choose;
	tmp.userid = GetdwAccountId();
	tmp.username = GetstrUserName();
	tmp.content = content;
	tmp.viplv = GetdwVipLv();
	sWorld->AddWorldChat(tmp);
//	SendPacket(&info);
}

void CRole::HandlerWorldBroadCast(WorldPacket &pkg)
{
	uint8_t choose;
	std::string content;
	uint32_t userid;
	pkg >> choose;
	pkg >> content;
	pkg >> userid;
	std::string temp = content;
	temp = CUtil::replace_all(CUtil::replace_all(CUtil::replace_all(temp, ",", ""), "=", ""), "|", "");
	IME_CHAR_LOG(GetdwAccountId(), "ACTION", "desc=%s", temp.c_str());
	PACKET_REMAIN_CHECK(pkg, CMD_SC_WORLD_BROADCAST_RESULT);

	if (content.size() > MAX_BROADCAST_LENGTH)
	{
		SendErrorMsg(ERRNO_MSG_BROADCAST_OVER_MAX_LENGTH, CMD_SC_WORLD_BROADCAST_RESULT);
		return;
	}

	if (choose == TRUMPET_WORLD_CHAT)
	{
//		STC_CONF_GOODS *pConf = CConfGoods::Find(TRUMPET_SHOPID);
//		if (pConf == NULL)
//		{
//			IME_ERROR("can not find this index %u in shop csv", TRUMPET_SHOPID);
//			SendErrorMsg(ERRNO_MSG_CSV_LOAD, CMD_SC_WORLD_BROADCAST_RESULT);
//			return;
//		}
//		if (pConf->dwLevelLimit != 0)
//		{
//			if (GetwLevel() < pConf->dwLevelLimit)
//			{
//				SendErrorMsg(ERRNO_MSG_SHOP_LEVEL_LIMIT, CMD_SC_WORLD_BROADCAST_RESULT);
//				return;
//			}
//		}
//
		CNameChecker::ReplaceString(content);

		WorldPacket info(CMD_SC_WORLD_BROADCAST_INFO);
		PkgWorldBroadCastInfo(choose, content, info);
		sSessCtrl->SendPkgToAll(info);	
	}
	else
	{
		if (m_vecTime[WORLD_BROADCAST_TIME] + GlobalConfig::WorldBroadCD >= time(NULL))
		{
			SendErrorMsg(ERRNO_MSG_CHAT_IN_CD, CMD_SC_WORLD_BROADCAST_RESULT);
			return;
		}
		CNameChecker::ReplaceString(content);

		WorldPacket info(CMD_SC_WORLD_BROADCAST_INFO);
		PkgWorldBroadCastInfo(choose, content, info);
		if (choose == NORMAL_WORLD_CHAT)
		{
			sSessCtrl->SendPkgToAll(info);	
		}
		else if (choose == PRIVATE_CHAT)
		{
		}
		else if (choose == GROUP_CHAT)
		{

		}
		else
		{
			IME_LOG("can not support this chat type %u", choose);
		}

		m_vecTime[WORLD_BROADCAST_TIME] = time(NULL);
	}	
	IME_CHAT_LOG("type %u, userid %u content %s", choose, userid, content.c_str());

	WorldPacket res(CMD_SC_WORLD_BROADCAST_RESULT);
	res << (uint16_t) 0;
	SendPacket(&res);
	return;
}

int CRole::OtherDataGet()
{
	std::string tmp;
	if (!CDBCtrl::GetUserDataOther(tmp, GetdwAccountId()))
	{
		IME_ERROR("get role other data fail");
		return -1;
	}
	ByteBuffer by;
	by.append(tmp.c_str(), tmp.size());
	by >> m_wOtherDataversion;
	if (m_wOtherDataversion == 0)
	{
		by >> m_dwGmFlushTime;
		by >> m_vecTime;
		by >> m_lCirculateId;
	}
	else
	{
		IME_ERROR("server version is too old than DB, other data version %u", m_wOtherDataversion);
		return -1;
	}

	// used to switch data from one version to other version
	if(m_wOtherDataversion == 0)
	{
	}
	return 0;
}

void CRole::OtherDataSave()
{
	ByteBuffer by;
	by << (uint32_t) 0;
	by << m_dwGmFlushTime;
	by << m_vecTime;
	by << m_lCirculateId;
	std::string tmp;
	tmp.append((const char *)by.contents(), by.size());

	CDBCtrl::SaveUserDataOther(tmp, GetdwAccountId());
}

void CRole::SendObjEffect(std::vector< std::vector<uint32_t> > tmp)
{
	WorldPacket info(CMD_SC_PRODUCT_GET_INFO);
	info << (uint16_t) PRODUCT_GET;
	info << (uint32_t) tmp.size();
	for (unsigned int i = 0; i < tmp.size(); i++)
	{
		std::vector<uint32_t> &v = tmp[i];
		info << v[0];
		info << v[1];
		info << v[2];
	}
	SendPacket(&info);
}

void CRole::SendEffectCombatResult(uint8_t combat_result, const std::vector<CombatResult> hero, uint32_t coin, uint32_t roleexp, uint32_t heroexp, uint32_t lv, uint16_t exp, uint32_t newlv, uint16_t newexp)
{
	WorldPacket info(CMD_SC_PRODUCT_GET_INFO);
	info << (uint16_t) COMBAT_RESULT;
	info << combat_result;
	info << (uint32_t)hero.size();
	for (unsigned int i = 0; i < hero.size(); i++)
	{
		info << hero[i].heropos;
		info << hero[i].lv;
		info << hero[i].exp;
		info << hero[i].explimit;
		info << hero[i].newlv;
		info << hero[i].newexp;
		info << hero[i].newexplimit;
	}
	info << coin;
	info << roleexp;
	info << heroexp;
	info << lv;
	info << exp;
	info << newlv;
	info << newexp;
	SendPacket(&info);
}

void CRole::HandlerEquipOpt(WorldPacket &pkg)
{
	uint8_t pos;
	uint8_t pos_equip;
	uint32_t itemindex;
	pkg >> pos;
	pkg >> pos_equip;
	pkg >> itemindex;

	IME_CHAR_LOG(GetdwAccountId(), "ACTION", "desc=userid %u equip item index %u", GetdwAccountId(), itemindex);
	PACKET_REMAIN_CHECK(pkg, CMD_SC_EQUIP_OPT_RESULT);
	
	if (pos >= POS_PRO_MAX || pos_equip >= POS_EQUIP_MAX || m_vecHero[pos] == NULL || m_vecEquip[pos].empty())
	{
		SendErrorMsg(ERRNO_MSG_DATA_ILLEGAL, CMD_SC_EQUIP_OPT_RESULT);
		return;
	}
	
	CItemBase *p = NULL;
	if (pos_equip == POS_EQUIP_SKILL)
	{
	}
	else
	{
		p = m_clsItemPacket->GetItem(itemindex);
		if (p == NULL)
		{
			IME_ERROR("can not find item index %u", itemindex);
			SendErrorMsg(ERRNO_MSG_DATA_ILLEGAL, CMD_SC_EQUIP_OPT_RESULT);
			return;
		}
		int pos[POS_EQUIP_MAX] = {ITEM_HEAD, ITEM_ARMOR, ITEM_SHOE, ITEM_WEAPON, ITEM_CLOAK, ITEM_WING};
		if (p->GetwType() != pos[pos_equip])
		{
			IME_ERROR("equip type is unvalid objid %u type %u", itemindex, p->GetwType());
			SendErrorMsg(ERRNO_MSG_DATA_ILLEGAL, CMD_SC_EQUIP_OPT_RESULT);
			return;
		}
		if (m_setEquipFilter.find(p->GetdwIndex()) != m_setEquipFilter.end())
		{
			IME_ERROR("duplicate equip objid %u", itemindex);
			SendErrorMsg(ERRNO_MSG_DUPLICATE_EQUIP, CMD_SC_EQUIP_OPT_RESULT);
			return;
		}	
	}
	
	m_vecEquip[pos][pos_equip] = itemindex;
	WorldPacket info(CMD_SC_EQUIP_OPT_RESULT);
	info << (uint16_t) 0;
	SendPacket(&info);
	return;
}

int CRole::LoadEquip()
{
	std::string temp;
	if (!CDBCtrl::GetUserEquipData(temp, GetdwAccountId()))
	{
		IME_ERROR("get data fail userid %u", GetdwAccountId());
		return -1;
	}
	std::vector<std::string> vect;
	CUtil::StrSplit(temp, "|", vect);
	for (unsigned int i = 0; i < std::min((uint32_t)vect.size(), (uint32_t)POS_PRO_MAX); i++)
	{
		CUtil::StrSplit(vect[i], ",", m_vecEquip[i]);
		if (m_vecEquip[i].size() >= POS_EQUIP_MAX) m_vecEquip[i].resize(POS_EQUIP_MAX, 0);
	}
	return 0;
}

void CRole::SaveEquip()
{
	std::vector<std::string> vect;
	std::string temp;
	std::string data;
	for (unsigned int i = 0; i < m_vecEquip.size(); i++)
	{
		CUtil::StrMerge(temp, ",", m_vecEquip[i]);
		vect.push_back(temp);
	}
	CUtil::StrMerge(data, "|", vect);
	CDBCtrl::SaveUserEquipData(data, GetdwAccountId());
}

void CRole::HandlerEquipInfo(int pos)
{
	WorldPacket info(CMD_SC_EQUIP_INFO);
	if (pos < 0)
	{
		info << (uint32_t)m_vecEquip.size();
		for (unsigned int i = 0; i < m_vecEquip.size(); i++)
		{
			info << (uint8_t) i;
			info << (uint32_t) m_vecEquip[i].size();
			for (unsigned int j = 0; j < m_vecEquip[i].size(); j++)
			{
				info << m_vecEquip[i][j];
			}
			info << m_vecHeroProperty[i].dwSelfAttack;
			info << m_vecHeroProperty[i].dwSelfDefence;
			info << m_vecHeroProperty[i].dwSelfStrength;
			info << m_vecHeroProperty[i].dwSelfHeal;
			info << m_vecHeroProperty[i].dwSelfPowerRecover;
			info << m_vecHeroProperty[i].dwSelfAttackSpeed;
			info << m_vecHeroProperty[i].dwSelfAttackTime;
			info << m_vecHeroProperty[i].dwSelfDodge;
			info << m_vecHeroProperty[i].dwSelfCrit;
			info << m_vecHeroProperty[i].dwSelfCritPower;
			info << m_vecHeroProperty[i].dwSelfHit;
			info << m_vecHeroProperty[i].dwSelfSuckBlood;

			info << m_vecHeroProperty[i].dwEquipAttack;
			info << m_vecHeroProperty[i].dwEquipDefence;
			info << m_vecHeroProperty[i].dwEquipStrength;
			info << m_vecHeroProperty[i].dwEquipHeal;
			info << m_vecHeroProperty[i].dwEquipPowerRecover;
			info << m_vecHeroProperty[i].dwEquipAttackSpeed;
			info << m_vecHeroProperty[i].dwEquipAttackTime;
			info << m_vecHeroProperty[i].dwEquipDodge;
			info << m_vecHeroProperty[i].dwEquipCrit;
			info << m_vecHeroProperty[i].dwEquipCritPower;
			info << m_vecHeroProperty[i].dwEquipHit;
			info << m_vecHeroProperty[i].dwEquipSuckBlood;

			info << m_vecHeroProperty[i].dwCombatValue;
		}
	}
	else if (pos >= 0 && pos < POS_PRO_MAX)
	{
		uint32_t i = pos;
		info << (uint32_t)1;
		info << (uint8_t) i;
		info << (uint32_t) m_vecEquip[i].size();
		for (unsigned int j = 0; j < m_vecEquip[i].size(); j++)
		{
			info << m_vecEquip[i][j];
		}
		info << m_vecHeroProperty[i].dwSelfAttack;
		info << m_vecHeroProperty[i].dwSelfDefence;
		info << m_vecHeroProperty[i].dwSelfStrength;
		info << m_vecHeroProperty[i].dwSelfHeal;
		info << m_vecHeroProperty[i].dwSelfPowerRecover;
		info << m_vecHeroProperty[i].dwSelfAttackSpeed;
		info << m_vecHeroProperty[i].dwSelfAttackTime;
		info << m_vecHeroProperty[i].dwSelfDodge;
		info << m_vecHeroProperty[i].dwSelfCrit;
		info << m_vecHeroProperty[i].dwSelfCritPower;
		info << m_vecHeroProperty[i].dwSelfHit;
		info << m_vecHeroProperty[i].dwSelfSuckBlood;

		info << m_vecHeroProperty[i].dwEquipAttack;
		info << m_vecHeroProperty[i].dwEquipDefence;
		info << m_vecHeroProperty[i].dwEquipStrength;
		info << m_vecHeroProperty[i].dwEquipHeal;
		info << m_vecHeroProperty[i].dwEquipPowerRecover;
		info << m_vecHeroProperty[i].dwEquipAttackSpeed;
		info << m_vecHeroProperty[i].dwEquipAttackTime;
		info << m_vecHeroProperty[i].dwEquipDodge;
		info << m_vecHeroProperty[i].dwEquipCrit;
		info << m_vecHeroProperty[i].dwEquipCritPower;
		info << m_vecHeroProperty[i].dwEquipHit;
		info << m_vecHeroProperty[i].dwEquipSuckBlood;

		info << m_vecHeroProperty[i].dwCombatValue;
	}
	else
	{
		IME_ERROR("unvalid prefession pos %u", pos);
	}
	info << m_dwTotalCombatValue;
	SendPacket(&info);
}

int CRole::LoadHero()
{
	ByteBuffer by;
	std::string temp;
	if (!CDBCtrl::GetUserHeroData(temp, GetdwAccountId()))
	{
		IME_ERROR("get data fail userid %u", GetdwAccountId());
		return -1;
	}
	by.append(temp.c_str(), temp.size());
	uint32_t dataversion;
	by >> dataversion;
	if (dataversion == 0)
	{
		uint32_t number = 0;
		uint32_t len = 0;
		by >> number;
		std::string oneHero;
		for (unsigned int i = 0; i < std::min((uint32_t)m_vecHero.size(), number) ; i++)
		{
			by >> len;
			by.read(oneHero, len);	
			ByteBuffer oneby;
			oneby.append(oneHero.c_str(), oneHero.size());

			m_vecHero[i] = new(std::nothrow) CHero();
			if (m_vecHero[i] == NULL)
			{
				IME_ERROR("new objid fail hero");
				return -1;
			}
			if (m_vecHero[i]->Init(this, oneby))
			{
				IME_ERROR("init hero fail userid %u", GetdwAccountId());
				return -1;
			}
		}
	}
	else
	{
		IME_ERROR("DB version data big than server version");
		return -1;
	}
	
	// used to change data
	if (dataversion == 0)
	{
	}
	return 0;
}

void CRole::SaveHero()
{
	ByteBuffer by;
	std::string temp;
	uint32_t number = 0;
	for (unsigned int i = 0; i < m_vecHero.size(); i++)
	{
		if (m_vecHero[i] != NULL)
		{
			number++;
		}
	}
	by << (uint32_t)0;
	by << number;
	for (unsigned int i = 0; i < m_vecHero.size(); i++)
	{
		ByteBuffer oneby;
		if (m_vecHero[i] != NULL)
		{
			m_vecHero[i]->DeSerilize(oneby);
			by << (uint32_t) oneby.size();
			by.append(oneby.contents(), oneby.size());
		}
	}
	temp.assign((const char *)by.contents(), by.size());
	CDBCtrl::SaveUserHeroData(temp, GetdwAccountId());
	return;
}

void CRole::HandlerHeroChange(WorldPacket &pkg)
{
	uint8_t pos_pro = 0;
	uint16_t avatarhair = 0;
	uint16_t avatareye = 0;
	uint16_t avatarnose = 0;
	uint16_t avatarmouth = 0;

	pkg >> pos_pro;
	pkg >> avatarhair;
	pkg >> avatareye;
	pkg >> avatarnose;
	pkg >> avatarmouth;

	PACKET_REMAIN_CHECK(pkg, CMD_SC_HERO_CHANGE_RESULT);
	IME_CHAR_LOG(GetdwAccountId(), "ACTION", "desc=change %u hero appearance hair %u eye %u nose %u mouth %u", GetdwAccountId(), avatarhair, avatareye, avatarnose, avatarmouth);

	if (pos_pro >= POS_PRO_MAX || m_vecHero[pos_pro] == NULL)
	{
		IME_ERROR("hero pos para is unvalid %u", pos_pro);
		SendErrorMsg(ERRNO_MSG_DATA_ILLEGAL, CMD_SC_HERO_CHANGE_RESULT);
		return;
	}

	m_vecHero[pos_pro]->SetwAvatarHair(avatarhair);
	m_vecHero[pos_pro]->SetwAvatarEye(avatareye);
	m_vecHero[pos_pro]->SetwAvatarNose(avatarnose);
	m_vecHero[pos_pro]->SetwAvatarMouth(avatarmouth);
	HandlerHeroInfo(pos_pro);
}

void CRole::HandlerHeroInfo(int pos)
{
	WorldPacket info(CMD_SC_HERO_INFO);
	if (pos < 0)
	{
		uint32_t number = 0;
		for (unsigned int i = 0; i < m_vecHero.size(); i++)
		{
			if (m_vecHero[i] != NULL)
				number++;	
		}

		info << (uint32_t) number;
		for (unsigned int i = 0; i < m_vecHero.size(); i++)
		{
			if (m_vecHero[i] == NULL)
				continue;
			info << (uint8_t) i;
			m_vecHero[i]->PkgProperty(info);
		}
		SendPacket(&info);
	}
	else
	{
		int i = std::min(pos, (int)POS_PRO_MAX); 
		if (m_vecHero[i] != NULL)
		{
			info << (uint32_t) 1;
			info << (uint8_t) i;
			m_vecHero[i]->PkgProperty(info);	
		}
		SendPacket(&info);
	}
}

void CRole::HandlerItemCombine(WorldPacket &pkg)
{
	uint32_t index;
	pkg >> index;

	PACKET_REMAIN_CHECK(pkg, CMD_SC_ITEM_COMBINE_RESULT);
	IME_CHAR_LOG(GetdwAccountId(), "ACTION", "desc=combine equip index %u", index);

	STC_CONF_ITEM *pConf = CConfItem::Find(index);
	if (pConf == NULL)
	{
		IME_ERROR("can not find item index %u", index);
		SendErrorMsg(ERRNO_MSG_CSV_LOAD, CMD_SC_ITEM_COMBINE_RESULT);
		return;
	}
	
	uint32_t arrtype[] = {ITEM_WEAPON, ITEM_ARMOR, ITEM_SHOE, ITEM_HEAD, ITEM_WING, ITEM_CLOAK};	
	if (std::find(arrtype, arrtype + sizeof(arrtype) / sizeof(uint32_t), pConf->wType) == arrtype + sizeof(arrtype) / sizeof(uint32_t)) 	
	{
		IME_ERROR("para is not unvalid type %u", pConf->wType);
		SendErrorMsg(ERRNO_MSG_DATA_ILLEGAL, CMD_SC_ITEM_COMBINE_RESULT);
		return;
	}

	uint32_t objid = index;

	CItemBase *pItem = GetclsItemPacket()->GetItem(objid);
	if (pItem != NULL) //upgrade
	{
		if (std::find(arrtype, arrtype + sizeof(arrtype) / sizeof(uint32_t), pItem->GetwType()) == arrtype + sizeof(arrtype) / sizeof(uint32_t)) 	
		{
			IME_ERROR("para is not unvalid type %u", pItem->GetwType());
			SendErrorMsg(ERRNO_MSG_DATA_ILLEGAL, CMD_SC_ITEM_COMBINE_RESULT);
			return;
		}

		CItemEquip *pEquip = (CItemEquip *)pItem;
		uint32_t combineid = GET_UPGRADE_COMBINE_ID(pEquip->GetwLevel() + 1, pEquip->GetdwIndex());
		const STC_CONF_UPGRADE *pUp = CConfUpgrade::Find(combineid);
		if (pUp == NULL)
		{
//			IME_ERROR("can not find upgrade csv index %u", combineid);
			SendErrorMsg(ERRNO_MSG_COMBINE_MAX_LEVEL, CMD_SC_ITEM_COMBINE_RESULT);
			return;
		}

		for (unsigned int i = 0; i < MAX_UPGRADE_COMBINE_NUMBER; i++)
		{
			if (GetclsItemPacket()->JudgeItemNumber(pUp->dwCombineItem[i], pUp->dwNumber[i]))
			{
//				IME_ERROR("item is not enough index %u number %u", pUp->dwCombineItem[i], pUp->dwNumber[i]);
				SendErrorMsg(ERRNO_MSG_ITEM_NOT_ENOUGH, CMD_SC_ITEM_COMBINE_RESULT);
				return;
			}
		}

		if (GetlCoin() < pUp->dwCombineConsumeCoin)
		{
			IME_ERROR("user have not enough coin %u", pUp->dwCombineConsumeCoin);
			SendErrorMsg(ERRNO_MSG_NOT_ENOUGH_COIN, CMD_SC_ITEM_COMBINE_RESULT);
			return;
		}
		
		uint64_t lcir = GetNewCirculateId();
		//del item
		for (unsigned int i = 0; i < MAX_UPGRADE_COMBINE_NUMBER; i++)
		{
			if (pUp->dwCombineItem[i] != 0)
			{
				GetclsItemPacket()->DelItem(pUp->dwCombineItem[i], SOURCE_COMBINE, lcir, pUp->dwNumber[i]);
				GetclsItemPacket()->ItemUpdate(pUp->dwCombineItem[i], CItem::DEL, pUp->dwNumber[i]);
			}
		}
		//del coin
		ChangeCoin(pUp->dwCombineConsumeCoin, SOURCE_COMBINE, lcir);
		SendProUpdate();
		
		//add item level
		pEquip->SetwLevel(pEquip->GetwLevel() + 1);
		GetclsItemPacket()->HandlerItemInfo(pEquip->GetdwObjId());

	}
	else // combine
	{
		uint32_t combineid = GET_UPGRADE_COMBINE_ID(0, index);
		const STC_CONF_UPGRADE *pUp = CConfUpgrade::Find(combineid);
//		STC_CONF_ITEM *pUp = CConfItem::Find(index);
		if (pUp == NULL)
		{
			IME_ERROR("can not find upgrade item csv index %u", index);
			SendErrorMsg(ERRNO_MSG_CSV_LOAD, CMD_SC_ITEM_COMBINE_RESULT);
			return;
		}

		for (unsigned int i = 0; i < MAX_UPGRADE_COMBINE_NUMBER; i++)
		{
			if (GetclsItemPacket()->JudgeItemNumber(pUp->dwCombineItem[i], pUp->dwNumber[i]))
			{
//				IME_ERROR("item is not enough index %u number %u", pUp->dwCombineItem[i], pUp->dwNumber[i]);
				SendErrorMsg(ERRNO_MSG_ITEM_NOT_ENOUGH, CMD_SC_ITEM_COMBINE_RESULT);
				return;
			}
		}

		if (GetlCoin() < pUp->dwCombineConsumeCoin)
		{
			IME_ERROR("user have not enough coin %u", pUp->dwCombineConsumeCoin);
			SendErrorMsg(ERRNO_MSG_NOT_ENOUGH_COIN, CMD_SC_ITEM_COMBINE_RESULT);
			return;
		}
		
		uint64_t lcir = GetNewCirculateId();
		//del item
		for (unsigned int i = 0; i < MAX_UPGRADE_COMBINE_NUMBER; i++)
		{
			if (pUp->dwCombineItem[i] != 0)
			{
				GetclsItemPacket()->DelItem(pUp->dwCombineItem[i], SOURCE_COMBINE, lcir, pUp->dwNumber[i]);
				GetclsItemPacket()->ItemUpdate(pUp->dwCombineItem[i], CItem::DEL, pUp->dwNumber[i]);
			}
		}
		//del coin
		ChangeCoin(pUp->dwCombineConsumeCoin, SOURCE_COMBINE, lcir);
		SendProUpdate();
		
		//add item to user
		std::vector<uint32_t> product,out;
		product.push_back(ITEM);
		product.push_back(index);
		product.push_back(1);
		GiveGameProduct(this, product, out, SOURCE_COMBINE, lcir);
		std::vector< std::vector<uint32_t> > temp;
		temp.push_back(out);
		SendObjEffect(temp);
	}
	WorldPacket info(CMD_SC_ITEM_COMBINE_RESULT);
	info << (uint16_t) 0;
	info << (uint32_t) index;
	SendPacket(&info);
	return;
}

int GiveGameProduct(CRole *pCRole, std::vector<uint32_t> in, std::vector<uint32_t> &out, int source, uint64_t cir)
{
	uint32_t type = in[0];
	uint32_t para1 = in[1];
	uint32_t para2 = in[2];
	out.clear();

	switch(type)
	{
		case PROPERTY:
			{
				if (para1 == RES_COIN)
				{
					pCRole->ChangeCoin(para2, source);
					pCRole->SendProUpdate();
				}
				else if (para1 == RES_DOLLAR)
				{
					uint32_t order_id = pCRole->GetNewObjId();

					pCRole->ChangeDollar(para2, source, cir);
					pCRole->SendProUpdate();
					CDBCtrl::LogShopRecord(pCRole->GetdwAccountId(), order_id, para2, 0, 1, E_DC_GIVE);	
				}
				else if (para1 == RES_VIP_EXP)
				{
					pCRole->ChangeVipExp(para2);
					pCRole->SendProUpdate();
				}
				else if (para1 == RES_ROLE_EXP)
				{
					pCRole->AddExp(para2);
					pCRole->Calculate(true);
				}
				else if (para1 == RES_HERO_EXP)
				{
					const std::vector< CHero* > hero = pCRole->GetvecHero();
					for (unsigned int i = 0; i < hero.size(); i++)
					{
						if (hero[i] == NULL)
							continue;
						hero[i]->AddExp(para1);
						hero[i]->Calculate();
						pCRole->Calculate();
						pCRole->HandlerHeroInfo(i);
					}
					pCRole->HandlerEquipInfo();
				}
				else
				{
					IME_ERROR("can not support this property index %u", para1);
					return -1;
				}
				out.push_back(EFFECT_PROPERTY);
				out.push_back(para1);
				out.push_back(para2);
			}
			break;
		case ITEM:
			{
				uint32_t objid;
				pCRole->GetclsItemPacket()->AddItem(para1, objid, source, cir, para2);
				pCRole->GetclsItemPacket()->ItemUpdate(objid, CItem::ADD, para2);
				out.push_back(EFFECT_ITEM);
				out.push_back(para1);
				out.push_back(para2);
			}
			break;
		default:
			IME_ERROR("unvalid type %u", type);
			return -1;
	}
	return 0;
}

int IsObjValid(std::vector< std::vector<uint32_t> > vproduct)
{
	for (unsigned int i = 0; i < vproduct.size(); i++)
	{
		std::vector<uint32_t>& v = vproduct[i];

		uint32_t type = v[0];
		uint32_t para1 = v[1];
//		uint32_t para2 = v[2];

		switch(type)
		{
			case PROPERTY:
				{
					if (para1 == RES_COIN)
					{
						continue;
					}
					else if (para1 == RES_DOLLAR)
					{
						continue;	
					}
					else if (para1 == RES_VIP_EXP || para1 == RES_ROLE_EXP || para1 == RES_HERO_EXP)
					{
						continue;
					}
					else
					{
						return -1;
					}
				}
				break;
			case ITEM:
				{
					STC_CONF_ITEM *pConf = CConfItem::Find(para1);
					if (!pConf)
						return -1;
				}
				break;
			default:
				return -1;
		}
	}
	return 0;
}

int IsObjValidDropGroup(const std::vector< std::vector<uint32_t> > &vecRule, const std::vector< std::vector<OneProduct> > &vecDropData, const DropData &common)
{
	for (unsigned int i = 0; i < vecRule.size(); i++)
	{
		if (vecRule[i].empty())
		{
			IME_ERROR("rule vector is null");
			return -1;
		}

		switch(vecRule[i][0])
		{
			case DROP_BY_NUMBER:
				{
					if (vecRule[i].size() < 3)
					{
						IME_ERROR("rule para size is unvalid");
						return -1;
					}
					uint32_t n = (vecRule[i].size() - 1) / 2;
					for (unsigned int j = 0; j < n; j++)
					{
						if (vecRule[i][j * 2 + 2] >= vecDropData.size())
						{
							IME_ERROR("rule %u dropgroupindex %u is unvalid", i, vecRule[i][j * 2 + 2]);
							return -1;
						}
					}
				}
				break;
			case DROP_BY_SERVER:
			case DROP_BY_ROLE:
			case DROP_BY_CHANNEL:
				{
					if (vecRule[i].size() != 4)
					{
						IME_ERROR("rule para size is unvalid");
						return -1;
					}
					if (vecRule[i][2] >= vecDropData.size())
					{
						IME_ERROR("rule %u dropgroupindex %u is unvalid", i, vecRule[i][3]);
						return -1;
					}
				}
				break;
			case DROP_BY_PROBABILITY:
				{
					if (vecRule[i].size() < 3)
					{
						IME_ERROR("rule para size is unvalid");
						return -1;
					}
					uint32_t n = vecRule[i].size() - 2;
					if (n > vecDropData.size())
					{
						IME_ERROR("rule probability number bigger than drop data");
						return -1;
					}
				}
				break;
			case DROP_BY_DIRECT:
				{
					if (vecRule[i].size() != 3)
					{
						IME_ERROR("rule para size is unvalid");
						return -1;
					}
					if (vecRule[i][1] >= vecDropData.size())
					{
						IME_ERROR("rule %u dropgroupindex %u is unvalid", i, vecRule[i][3]);
						return -1;
					}
				}
			case DROP_BY_REAL_PROBABILITY:
				{
					if (vecRule[i].size() < 3)
					{
						IME_ERROR("rule para size is unvalid");
						return -1;
					}
					uint32_t n = vecRule[i].size() - 2;
					if (n > vecDropData.size())
					{
						IME_ERROR("rule probability number bigger than drop data");
						return -1;
					}
				}
			default:
				IME_ERROR("unvalid rule type %u", vecRule[i][0]);
				return -1;
		}
	}
//	if (IsCheckNone)
//	{
//		if (GetDropGroupId(vecRule, vecDropData, common).empty())
//		{
//			IME_ERROR("can not get product data");
//			return 1;
//		}
//	}
	return 0;
}

std::vector<OneProduct> GetDropGroupId(const std::vector< std::vector<uint32_t> > &vecRule, const std::vector< std::vector<OneProduct> > &vecDropData, DropData &common)
{
	for (unsigned int i = 0; i < vecRule.size(); i++)
	{
		switch(vecRule[i][0])
		{
			case DROP_BY_NUMBER:
				{
					uint32_t n = (vecRule[i].size() - 1) / 2;
					for (unsigned int j = 0; j < n; j++)
					{
						uint32 seqno = vecRule[i][j * 2 + 1];
						if (common.number == seqno)
						{
							return vecDropData[seqno];
						}
					}
				}
				break;
			case DROP_BY_SERVER:
			case DROP_BY_ROLE:
			case DROP_BY_CHANNEL:
				{
					uint32_t seqno = vecRule[i][2];
					if (common.number < vecRule[i][1])
					{
						if (CUtil::RandEither(vecRule[i][3]))
							return vecDropData[seqno];
					}
				}
				break;
			case DROP_BY_PROBABILITY:
				{
					std::vector<int> vect;
					for (unsigned int j	= 1; j < vecRule[i].size(); j++)
					{
						vect.push_back(vecRule[i][j]);
					}
					int ret = CUtil::RandFactor(vect);
					if (ret != 0)
					{
						return vecDropData[ret - 1];
					}
				}
				break;
			case DROP_BY_DIRECT:
				{
					uint32_t seqno = vecRule[i][1];
					if (common.number < seqno)
					{
						if (CUtil::RandEither(vecRule[i][2]))
							return vecDropData[seqno];
					}
				}
				break;
			case DROP_BY_REAL_PROBABILITY:
				{
					std::vector<uint32_t> vectmp;
					for (unsigned int j = 1; j < vecRule[i].size(); j++)
					{
						vectmp.push_back(vecRule[i][j]);
					}
					if (common.count.size() < vectmp.size())
					{
						common.count.resize(vectmp.size(), 0);
					}

					bool isreset = true;
					for (unsigned int j = 0; j < vectmp.size(); j++)
					{
						int a = vectmp[j] - common.count[j];
						vectmp[j] = a < 0 ? 0 : a;
						if (vectmp[j] != 0)
							isreset = false;
					}

					if (isreset)
					{
						for (unsigned j = 0; j < vectmp.size(); j++)
						{
							vectmp[j] = vecRule[i][j + 1];
							common.count[j] = 0;
						}
					}

					std::vector<uint32_t> vecPro;
					for (unsigned j = 0; j < vectmp.size(); j++)
					{
						if (vectmp[j] != 0)
							vecPro.push_back(j);
					}

					if (vecPro.size() != 0)
					{
						int ret = CUtil::RandByRange(0, vecPro.size());
						common.count[ret]++;
						if (vecPro[ret] != 0)
						{
							return vecDropData[vecPro[ret] - 1];
						}
					}
				}
				break;
			default:
				return std::vector<OneProduct>();
		}
	}
	common.number++;
	return std::vector<OneProduct>();
}

int CRole::HeroCome(int pos)
{
	pos = std::min(pos, (int)POS_PRO_MAX);
	int heroindex[] = {FIRST_HERO, SECOND_HERO, THIRD_HERO, FORTH_HERO};
	if (m_vecHero[pos] != NULL)
	{
		IME_ERROR("this hero already have");
		return -1;
	}

	m_vecHero[pos] = new(std::nothrow) CHero();
	if (m_vecHero[pos] == NULL)
	{
		IME_ERROR("new objid fail hero");
		return -1;
	}
	if (m_vecHero[pos]->Create(this, heroindex[pos]))
	{
		IME_ERROR("init hero fail userid %u", GetdwAccountId());
		SAFE_DELETE_OBJECT(m_vecHero[pos]);
		return -1;
	}

	HandlerHeroInfo();	
	return 0;
}
