#include <new>
#include "World.h"
#include "UserSession.h"
#include "ShardingDB.h"
#include "WorldDb.h"
#include "DatabaseMysql.h"
#include "Log.h"
#include "RelayClientSession.h"
#include "CmdInnerDefine.h"
#include "Role.h"
#include "CmdDefine.h"
#include "ConfigData.h"
#include "DBCtrl.h"
#include "google/malloc_extension.h"

#include "ConfigData.h"
#include "GlobalConfig.h"
#include "ErrorMsg.h"
#include "Notice.h"
#include "Other.h"
#include "CenterDBCtrl.h"
#include "GmCommandExt.h"
#include "EnumDefines.h"

//extern DatabaseMysql LoginDatabase;        ///< Accessor to the login database
extern CShardingDB WorldDb;
extern DatabaseMysql OperateDatabase;       ///< Accessor to the Operation database

extern std::string g_strConfigPath;


CWorld * CWorld::m_pInstance = NULL;

CWorld::CWorld()
{
}

CWorld::~CWorld()
{
}

CWorld * CWorld::GetInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new CWorld();
	}
	return m_pInstance;
}

bool CWorld::InitSettings()
{
	m_timers[WUPDATE_PINGDB].SetInterval(1 * 60 * 1000);	// 1分钟
	m_timers[WUPDATE_30min].SetInterval(30 * 60 * 1000);
	m_timers[WUPDATE_LOGIN].SetInterval(30 * 1000);			// 30秒
	m_timers[WUPDATE_10min].SetInterval(10 * 60 * 1000);	// 
	m_timers[WUPDATE_1s].SetInterval(1 * 1000);	// 
	m_timers[WUPDATE_CHARGE].SetInterval(5 * 1000);	// 

	m_pCNotice = new CNotice();
	assert(m_pCNotice);
	if (!m_pCNotice->Init())
	{
		IME_ERROR("notice init fail");
		return false;
	}
	m_pCAnnouncement = new CAnnouncement();
	assert(m_pCAnnouncement);
	if (!m_pCAnnouncement->Init())
	{
		IME_ERROR("announcement init fail");
		return false;
	}

	SServerData tmp;	
	for (unsigned int i = 0; i < m_vecServerId.size(); i++)
	{
//		IME_DEBUG("game serverid %u", m_vecServerId[i]);
		uint8_t CanLogin = 0;
		uint8_t Status = 0;
		uint8_t IsNew = 0;
		std::string ServerName;
		std::string Domain;
		std::string ResUrl;
		if (!CDBCtrl::GetLoginInfo(m_vecServerId[i], m_strIp, m_nPort, GetOnlineNum(), CanLogin, Status, IsNew, ServerName, Domain, ResUrl))
		{
			IME_ERROR("Get server info fail");
			return false;
		}
		tmp.serverid = m_vecServerId[i];
		tmp.canlogin = CanLogin;
		tmp.status = Status;
		tmp.isnew = IsNew;
		tmp.servername = ServerName;
		tmp.ip = m_strIp;
		tmp.port = m_nPort;
		tmp.domain = Domain;
		tmp.resurl = ResUrl;
		m_mapServer[m_vecServerId[i]] = tmp;
	}

	UpdateLoginInfo();

	if (!CenterDBCtrl::InitGmCommand())
	{
		IME_ERROR("init operate command fail");
		return false;
	}

	std::string strchat;
	if (!CDBCtrl::GetGlobalData(DB_GLOBAL_CHAT, strchat))
	{
		IME_ERROR("get global data fail");
		return false;
	}

	m_lstWorldBroadCast.clear();
	ByteBuffer by;
	by.append(strchat.data(), strchat.size());
	SWorldChat tchat;
	uint32_t len;
	by >> len;
	for (unsigned int i = 0; i < len; i++)
	{
		by >> tchat.choose;
		by >> tchat.userid;
		by >> tchat.username;
		by >> tchat.content;
		by >> tchat.viplv;
		m_lstWorldBroadCast.push_back(tchat);
	}

	std::string stra;
	if (!CDBCtrl::GetGlobalData(DB_GLOBAL_WHITE_LIST, stra))
	{
		IME_ERROR("get global data fail");
		return false;
	}
	CUtil::StrSplit(stra, ",", m_vecWhiteList);
	CDBCtrl::GetUserName(m_setAllUserName);

	IME_LOG("notice if server have some operations, please wait");
//	std::string strc;
//	if (!CDBCtrl::GetGlobalData(DB_GLOBAL_SERVER_OPERATIONS, strc))
//	{
//		IME_ERROR("get global data fail");
//		return false;
//	}
//
//	std::vector<uint32_t> vecOpt;
//	CUtil::StrSplit(strc, ",", vecOpt);
//	if (std::find(vecOpt.begin(), vecOpt.end(), (uint32_t)ALL_ROLE_CARDPACKET) == vecOpt.end())
//	{
//		vecOpt.push_back(ALL_ROLE_CARDPACKET);
//		std::string stra;
//		CUtil::StrMerge(stra, ",", vecOpt);
//		CDBCtrl::SaveGlobalData(stra, DB_GLOBAL_SERVER_OPERATIONS);
//	}
	IME_LOG("notice operations end");

	if (!CDBCtrl::GetAllUserBaseData(m_mapRoleBase))
	{
		IME_ERROR("get all user data fail");
		return false;
	}
	
	return true;
}


void CWorld::AddUserAuth( uint32 dwUserId, CHandlerPlayersession*  pSession)
{
	m_mapUserAuth[dwUserId] = pSession;

	// send relay server
//	WorldPacket pkg(CMD_RELAY_CS_LOGIN);
//	pkg << dwUserId;
//	sSessCtrl->SendToRelay(pkg);
}

void CWorld::DelUserAuth( uint32 dwUserId )
{
	m_mapUserAuth.erase(dwUserId);

	//send relay server
//	WorldPacket pkg(CMD_RELAY_CS_LOGOUT);
//	pkg << dwUserId;
//	sSessCtrl->SendToRelay(pkg);
}

CRole* CWorld::FindUserRole( uint32 dwUserId )
{
	MapSessionByUserId::iterator it = m_mapUserAuth.find(dwUserId);
	return it == m_mapUserAuth.end() ? NULL : it->second->GetRole();
}

CHandlerPlayersession* CWorld::FindSess(uint32 dwUserId)
{
	MapSessionByUserId::iterator it = m_mapUserAuth.find(dwUserId);
	return it == m_mapUserAuth.end() ? NULL : it->second;
}

void CWorld::AllOffline()
{
//	IME_ERROR("OFFLINE SESSION NUM[Num=%u]", (uint32)m_sessions.size());
	IME_ERROR("OFFLINE ROLE NUM[Num=%u]", (uint32)m_mapUserAuth.size());
	WorldPacket info(CMD_SC_CLOSE_CONNECT);
	sSessCtrl->SendPkgToAll(info);

//	SessionMap::iterator it = m_sessions.begin();
//	for ( ; it !=m_sessions.end(); ++it)
//	{
//		CUserSession* pSess = it->second;
//		pSess->Offline();
//		delete pSess;
//	}
	// save some group data
//	UpdateLoginInfo();
	SaveAllData();

}

void CWorld::Update1min()
{
//	IME_DEBUG("Ping MySQL to keep connection alive");
	//LoginDatabase.Ping();
	//CenterDatabase.Ping();
	WorldDb.Ping();
	CenterDBCtrl::ReadNewGmCommand();
}

void CWorld::Update30min()
{
	MallocExtension::instance()->ReleaseFreeMemory();
}

void CWorld::Update10min()
{
	SaveAllData();		
}

void CWorld::UpdateLoginInfo()
{
	m_pCNotice->HandlerSendSysBroadCast();
	for (unsigned int i=0; i< m_vecServerId.size(); i++)
	{
		uint32_t serverid = m_vecServerId[i];
		CDBCtrl::UpdateLoginInfo(serverid, m_strIp, m_nPort, GetOnlineNum(), m_mapServer[serverid].canlogin, m_mapServer[serverid].status, m_mapServer[serverid].isnew, m_mapServer[serverid].servername, m_mapServer[serverid].domain, m_mapServer[serverid].resurl);
		CenterDBCtrl::UpdateGameServerInfo(serverid, m_mapServer[serverid].servername, m_mapServer[serverid].domain, m_mapServer[serverid].ip, m_mapServer[serverid].port, m_mapServer[serverid].resurl, GetOnlineNum(), CUtil::Uint32ToString(INNER_VERSION).c_str(), "", m_mapServer[serverid].canlogin, m_mapServer[serverid].status, 0); 
	}
}

void CWorld::Update1s()
{
	CenterDBCtrl::UpdateGmCommand();
}

void CWorld::UpdateCharge()
{
	/*
//	IME_DEBUG("charge get record");
	uint32_t order_id = 0;
	std::list<STC_CHARGE_INFO> listtmp;
	std::list<STC_CHARGE_INFO>::iterator it;
	if (CenterDBCtrl::GetUnhandledCharge(listtmp))
	{
		for(it = listtmp.begin(); it != listtmp.end(); it++)
		{
			uint8_t IsOnline = 1;
//			IME_ERROR("role id %u", it->dwRoleId);
			CRole *pCRole = sWorld->FindUserRole(it->dwRoleId);
			if (pCRole == NULL)
			{
				IsOnline = 0;
				continue;
			}

			if (!(pCRole->IsInitRoleInfo()))
			{
				continue;
			}

			if (!CDBCtrl::GetShopOrderId(pCRole->GetdwAccountId(), order_id))
			{
				IME_ERROR("Get shopid orderid fail user_id %u", pCRole->GetdwAccountId());
				continue;
			}

			uint32_t totalnumber = it->dwGoodsQuantity;
			uint8_t method = 0;
			if (it->dwGoodsId == 0)
			{
				totalnumber = 1;
				method = 1;
			}

			STC_CONF_STORE *pConfStore = NULL;
			if (method == 0)
			{
				pConfStore = CConfStore::Find(it->dwGoodsId);
				if (pConfStore == NULL)
				{
					IME_ERROR("can not recognition this goods index %u", it->dwGoodsId);
					continue;
				}
			}
			else
			{
//				pConfStore = CConfStore::FindByDollar(it->dwGoodsQuantity / 100, it->dwKind);
				pConfStore = CConfStore::FindByRMBWithRange(it->dwGoodsQuantity / 100, it->dwKind);
				if (pConfStore == NULL)
				{
					IME_ERROR("can not recognition this goods dollar index %u, kind %u", it->dwGoodsQuantity, it->dwKind);
					continue;
				}
			}

			if (pConfStore->byObjType != STORE_OBJ_RMB)
			{
				IME_ERROR("store index %u goods id %u is not rmb record", pConfStore->dwIndex, it->dwGoodsId);
				continue;
			}

			IME_LOG("role id %u charge %u", it->dwRoleId, pConfStore->dwIndexNumber);
			
			uint32_t dollar = 0;
			uint8_t flag = pCRole->GetbyFlag();
//			uint32_t vipexp = pConfStore->dwObjNumber;
//			uint32_t rmb = pConfStore->dwObjNumber;
			uint32_t vipexp = 0;
			uint32_t rmb = 0;

			uint8_t IsDouble = 0;
			
			if (IS_ALREADY_DOUBLE_CHARGE(flag))
			{
				if (method == 0)
				{
					dollar = pConfStore->dwIndexNumber * it->dwGoodsQuantity;
					vipexp = pConfStore->dwObjNumber * it->dwGoodsQuantity;
					rmb = pConfStore->dwObjNumber * it->dwGoodsQuantity;
				}
				else
				{
					dollar = it->dwGoodsQuantity / 100.0 / pConfStore->dwObjNumber * pConfStore->dwIndexNumber;
					vipexp = it->dwGoodsQuantity / 100.0;
					rmb = it->dwGoodsQuantity / 100.0;
				}
			}
			else
			{
				if (method == 0)
				{
					vipexp = pConfStore->dwObjNumber * it->dwGoodsQuantity;
					rmb = pConfStore->dwObjNumber * it->dwGoodsQuantity;
					if (vipexp >= CHARGE_DOUBLE_LIMIT)
					{
						dollar = pConfStore->dwIndexNumber * it->dwGoodsQuantity * FIRST_CHARGE_MULTI_PARA / 100.0;
						IsDouble = 1;
					}
					else
					{
						dollar = pConfStore->dwIndexNumber * it->dwGoodsQuantity;
					}
				}
				else
				{
					vipexp = it->dwGoodsQuantity / 100.0;
					rmb = it->dwGoodsQuantity / 100.0;
					if (vipexp >= CHARGE_DOUBLE_LIMIT)
					{
						dollar = it->dwGoodsQuantity / 100.0 / pConfStore->dwObjNumber * pConfStore->dwIndexNumber * FIRST_CHARGE_MULTI_PARA / 100.0;
//						dollar = pConfStore->dwIndexNumber * FIRST_CHARGE_MULTI_PARA / 100.0;
						IsDouble = 1;
					}
					else
					{
						dollar = it->dwGoodsQuantity / 100.0 / pConfStore->dwObjNumber * pConfStore->dwIndexNumber;
					}
				}
			}

			if (!CenterDBCtrl::ChargeHandled(it->dwAutoId, dollar, pCRole->GetSession()->GetRemoteIP(), pCRole->GetSession()->GetLoginDevice(), pCRole->GetSession()->GetLoginDeviceType(), pCRole->GetSession()->GetLoginDeviceUid()))
			{
				IME_ERROR("update charge fail");
				continue;
			}
			CDBCtrl::LogShopRecord(pCRole->GetdwAccountId(), order_id, dollar, pConfStore->dwStoreIndex, totalnumber, E_DC_CHARGE);	

			SCommonActivePara chargepara;
			chargepara.para1 = rmb;
			chargepara.para2 = 0;
			pCRole->GetCActive()->ChangeCommonActive(CHARGE_SINGLE_ACTIVE_ID, chargepara, 1);	
			pCRole->GetCActive()->ChangeCommonActive(CHARGE_ACCUMULATE_ACTIVE_ID, chargepara, 1);	
			pCRole->GetCActive()->ChangeCommonActive(CHARGE_CYCLE_ACTIVE_ID, chargepara, 1);	

			if (!IS_ALREADY_FIRST_CHARGE(flag))
			{
				flag = OPEN_FIRST_PRIZE(flag);
				flag = FIRST_CHARGE(flag);
				pCRole->SetbyFlag(flag);
			}

			if (IsDouble)
			{
				flag = OPEN_DOUBLE_CHARGE(flag);
				pCRole->SetbyFlag(flag);
			}

			uint16_t oldviplv = pCRole->GetwVipLv();

			pCRole->ChangeDollar(dollar, SOURCE_CHARGE);
			pCRole->ChangeVipExp(vipexp);
			pCRole->Calculate(false);
			pCRole->HandlerInfoOpt();

			uint32_t luck = pCRole->GetdwLuck() + vipexp * DOLLAR_LUCK_PARA;
			uint16_t newviplv = pCRole->GetwVipLv();
			STC_CONF_VIP *pVipConf = CConfVip::Find(newviplv);
			if (newviplv > oldviplv)
			{
				if (pVipConf == NULL)
				{
					IME_ERROR("vip lv %u can not find in vip csv", newviplv);
				}
				else
				{
					luck = pVipConf->dwLuckMax + vipexp * DOLLAR_LUCK_PARA;
				}
				CDataPush dpush;
				dpush.HandlerDataPushVip(pCRole, newviplv);
			}

			pCRole->SetdwLuck(luck);
			pCRole->SetdwChargeLuck(pCRole->GetdwChargeLuck() + vipexp * DOLLAR_LUCK_PARA);

			pCRole->SaveAllData();
			order_id++;
			if (IsOnline)
			{
				pCRole->SendProUpdate();
				CDataPush dpush;
				dpush.m_byCharge = 1;
				dpush.m_dwChargeNumber = dollar;
				dpush.HandlerDataPush(pCRole);	
			}
		}
	}
*/
}

void CWorld::SetServerId(std::string strServerId)
{
	CUtil::StrSplit(strServerId, "'", m_vecServerId);
}
void CWorld::SetIp(std::string &strIp)
{
	m_strIp = strIp;
}
void CWorld::SetPort(int nPort)
{
	m_nPort = nPort;
}
uint32 CWorld::GetOnlineNum()
{
//	return m_sessions.size();
	return m_mapUserAuth.size();
}

void CWorld::GetRoleList( std::vector<CRole*>& vecRole )
{
	MapSessionByUserId::iterator it = m_mapUserAuth.begin();
	for ( ; it != m_mapUserAuth.end(); ++it)
	{
		vecRole.push_back(it->second->GetRole());
	}
}

void CWorld::SaveAllData()
{
	m_pCNotice->SaveData();

	ByteBuffer by;
	by << (uint32_t) m_lstWorldBroadCast.size();
	std::list<SWorldChat>::iterator it;
	for (it = m_lstWorldBroadCast.begin(); it != m_lstWorldBroadCast.end(); it++)
	{
		by << it->choose;
		by << it->userid;
		by << it->username;
		by << it->content;
		by << it->viplv;
	}
	std::string strt;
	strt.assign((const char *)by.contents(), by.size());
	CDBCtrl::SaveGlobalData(strt, DB_GLOBAL_CHAT); 

	std::string stra;
	CUtil::StrMerge(stra, ",", m_vecWhiteList);
	CDBCtrl::SaveGlobalData(stra, DB_GLOBAL_WHITE_LIST);
}

void CWorld::AddWorldChat(const SWorldChat &tmp)
{
	m_lstWorldBroadCast.push_back(tmp);
	if (m_lstWorldBroadCast.size() > MAX_WORLD_CHAT_NUMBER)
	{
		m_lstWorldBroadCast.pop_front();
	}
}

void CWorld::HandlerWorldChatInfo(CRole *pCRole)
{
	std::list<SWorldChat>::iterator it;
	for (it = m_lstWorldBroadCast.begin(); it != m_lstWorldBroadCast.end(); it++)
	{
		WorldPacket info(CMD_SC_WORLD_BROADCAST_INFO);
		info << it->choose;
		info << it->userid;
		info << it->username;
		info << it->content;
		info << it->viplv;
		pCRole->SendPacket(&info);
	}
}

void CWorld::PkgWorldChat(SWorldChat tmp, WorldPacket &info)
{
	info.clear();
	info.SetOpcode(CMD_SC_WORLD_BROADCAST_INFO);
	info << tmp.choose;
	info << tmp.userid;
	info << tmp.username;
	info << tmp.content;
	info << tmp.viplv;

	AddWorldChat(tmp);
}

void CWorld::AddRoleBase(const RoleBase &data)
{
	m_mapRoleBase[data.dwAccountId] = data;
}

const RoleBase *CWorld::GetRoleBase(uint32_t dwAccountId)
{
	if (m_mapRoleBase.find(dwAccountId) != m_mapRoleBase.end())
	{
		return &m_mapRoleBase[dwAccountId];
	}
	else 
	{
		return NULL;
	}
}
