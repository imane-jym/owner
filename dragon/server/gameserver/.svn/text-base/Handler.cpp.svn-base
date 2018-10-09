/*
 * =====================================================================================
 *
 *       Filename:  Handler.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年09月22日 16时53分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "Handler.h"
#include "World.h"
#include "PlayerSession.h"
#include "RelayClientSession.h"

#include <string>
#include "Set.h"

#include "Role.h"
#include "DatabaseMysql.h"
#include "miniini/miniini.h"
#include "ShardingDB.h"
#include "GmCmdPro.h"
#include "ConfigData.h"
#include "IDCtrl.h"
#include "Log.h"

#include "PlayerSession.h"
#include "Util.h"
#include "DBCtrl.h"
#include <signal.h>
#include <iostream>
#include <vector>
#include <string>
#include "GlobalConfig.h"
#include "NameChecker.h"
#include "WorldDb.h"
#include "CenterDBCtrl.h"

#include "CmdDefine.h"
#include "EnumDefines.h"
#include "DatabaseMysql.h"
#include "QueryResult.h"
#include "Field.h"
#include "ErrorMsg.h"
#include "CmdInnerDefine.h"
#include "WorldPacket.h"
#include "md5.h"
#include "Other.h"
#include "Task.h"

CShardingDB WorldDb;				///< Accessor to the sharding world database
DatabaseMysql LoginDatabase;        ///< Accessor to the login database
DatabaseMysql OperateDatabase;       ///< Accessor to the Operation database

//CLuaState g_luaState;
extern INIFile g_serverIni;
std::string g_strConfigPath;
//int g_nVersion;
std::string g_strWorldDatabaseName;
std::string g_strOperateDatabaseName;

bool StartDB()
{

	INISection * database = g_serverIni.GetSection("other");
	if (!database)
	{
		IME_ERROR("Miss section [other] in gameserver.ini");
		return false;
	}

	std::string dbstring;

//	if (!database->ReadString("centerdatabase",dbstring))
//	{
//		IME_ERROR("Missing centerdatabase info");
//		return false;
//	}
//    ///- Initialise the character database
//	if(!CenterDatabase.Initialize(dbstring.c_str()))
//	{
//		IME_ERROR("Cannot connect to centerdatabase %s",dbstring.c_str());
//		return false;
//	}

	if (!database->ReadString("logindatabase",dbstring))
	{
		IME_ERROR("Missing login database info");
		return false;
	}
    ///- Initialise the login database
	if(!LoginDatabase.Initialize(dbstring.c_str()))
	{
		IME_ERROR("Cannot connect to login database %s",dbstring.c_str());
		return false;
	}
	
	dbstring = "";
	if (!database->ReadString("operatedatabase",dbstring))
	{
		IME_ERROR("Missing operate database info");
		return false;
	}
    ///- Initialise the operate database
	if(!OperateDatabase.Initialize(dbstring.c_str()))
	{
		IME_ERROR("Cannot connect to login database %s",dbstring.c_str());
		return false;
	}

	std::vector<std::string> vectmp;
	CUtil::StrSplit(dbstring, "'", vectmp);
	g_strOperateDatabaseName = vectmp[4];

	// world db num
	int nWorldDbNum = 0;
	if (!database->ReadInt("wdb_sharding_num", nWorldDbNum))
	{
		IME_ERROR("Error, not read wdb sharding num");
		return false;
	}
	if (nWorldDbNum <=0)
	{
		IME_ERROR("Error, invalid wdb sharding num[%d]", nWorldDbNum);
		return false;
	}
	std::vector<std::string> vecStrDbInfo;
	for (int i = 0; i < nWorldDbNum; ++i)
	{
		char szNum[8];
		sprintf(szNum, "%d", i);
		std::string strWorldDbName= "wdb";
		strWorldDbName += szNum;
		std::string strDbInfo;
		if (!database->ReadString(strWorldDbName, strDbInfo))
		{
			IME_ERROR("Error, invalid world db info[%s]", strWorldDbName.c_str());
			return false;
		}
		vecStrDbInfo.push_back(strDbInfo);
	}

	std::vector<std::string> vecData;
	CUtil::StrSplit(vecStrDbInfo[0], "'", vecData);
	g_strWorldDatabaseName = vecData[4];

	if (!WorldDb.Init(nWorldDbNum, vecStrDbInfo))
	{
		IME_ERROR("WorldDb Init Fail!");
		return false;
	}

	//造表
	if (!CDBCtrl::CreateWorldDB())
	{
		IME_ERROR("CreateWorldDB ERROR");
		return false;
	}

	if (!CenterDBCtrl::InitCenterDB(&OperateDatabase, 0))
	{
		IME_ERROR("operate database init fail");
		return false;
	}

	return true;
}


bool HandlerInit(uint8_t thread)
{
	//to do implementation
//	IME_LOG("handler init %u", thread);
	if (thread == MAIN_THREAD)
	{
//		CSet::ExecutionTimeInterval = NETWORK_CHECK_SEC;
		srand(time(NULL));
		INISection * server = g_serverIni.GetSection("server");
		if (!server)
		{
			IME_ERROR("Miss section [server] in ***server.ini");
			return false;
		}
		int nPort = 0;
		if (!server->ReadInt("listen_port",nPort))
		{
			IME_ERROR("Miss listen_port");
			return false;
		}
		std::string strIp;
		if (!server->ReadString("bind_ip",strIp))
		{
			IME_ERROR("Miss bind_ip");
			return false;
		}
		INISection * configPath = g_serverIni.GetSection("other");
		if (!configPath)
		{
			IME_ERROR("Miss section [other] in server.ini");
			return false;
		}

		std::string strServerId;
		if (!server->ReadString("area_id",strServerId))
		{
			IME_ERROR("Miss server_id");
			return false;
		}

		sWorld->SetIp(strIp);
		sWorld->SetPort(nPort);
		sWorld->SetServerId(strServerId);

		//	int nVersion = 0;
		//	if (!configPath->ReadInt("version", nVersion))
		//	{
		//		IME_ERROR("Missing version info");
		//		return false;
		//	}
		//	g_nVersion = nVersion;

		std::string strConfigPath;
		if (!configPath->ReadString("config_path",strConfigPath))
		{
			IME_ERROR("Missing config_path info");
			return false;
		}
		g_strConfigPath = strConfigPath;

		if (!ConfInit(g_strConfigPath))
		{
			IME_ERROR("ConfInit Failed!");
			return false;
		}

		//全局参数初始化
		if (!GlobalConfig::Init(g_strConfigPath + "GlobalConfig.ini"))
		{
			IME_ERROR("GlobalConfig::Init failed!");
			return false;
		}

		std::string strKeyWordFile = g_strConfigPath + "keyword.txt";
		if (!CNameChecker::Init(strKeyWordFile.c_str()))
		{
			IME_ERROR("Load keyword.txt error");
			return false;
		}

		if (!StartDB())                     
		{
			IME_ERROR("StartDB failed");    
			return false;
		}

		//////////////////////////////////////////////////////////////////////////

		////////
		//	if (!g_luaState.Init())
		//	{
		//		IME_ERROR("luaState Init failed.");
		//		return false;
		//	}
		//	//tolua_LuaExport_open(g_luaState.GetState());
		//
		//	if (!CLuaCtrl::Init())
		//	{
		//		IME_ERROR("CLuaCtrl init error");
		//		return false;
		//	}

		CGmCmdPro::Init();
	}
	else if (thread == WORLD_THREAD)
	{
		if (!sWorld->InitSettings())
			return false;
	}
	return true;
}

void HandlerFinally(uint8_t thread)
{
	//to do implementation
//	IME_LOG("handler finally %u", thread);
	if (thread == MAIN_THREAD)
	{

	}
	else if (thread == WORLD_THREAD)
	{
		sWorld->AllOffline();
	}
}

void HandlerOntimer(uint32_t interval)
{
	//to do implementation
//	IME_LOG("handler Ontimer %u", interval);
	if (interval == TIMER_1S)
	{
		sWorld->Update1s();
	}
	else if (interval == TIMER_3S)
	{
	}
	else if (interval == TIMER_5S)
	{
		sWorld->UpdateCharge();
	}
	else if (interval == TIMER_30S)
	{
		sWorld->UpdateLoginInfo();
	}
	else if (interval == TIMER_1MIN)
	{
		sWorld->Update1min();
	}
	else if (interval == TIMER_30MIN)
	{
		sWorld->Update30min();
	}
	else if (interval == TIMER_10MIN)
	{
		sWorld->Update10min();
	}
}

CHandlerPlayersession::CHandlerPlayersession()
{
	m_pPlayer = NULL;
	m_strIp = "";

	//to do implementation
	InitOpcodeHandler();

	InitOpRelayPacket();
	m_dwBeatTime = getMSTime();
	m_dwAccountId = 0;

	m_pRole = NULL;
	m_eUserStatus = E_STATUS_CONNECTED;
}

CHandlerPlayersession::~CHandlerPlayersession()
{
	if (m_pRole)
	{
		//todo need do something?
		delete m_pRole;
		m_pRole = NULL;
	}
}

void CHandlerPlayersession::Process(WorldPacket &packet)
{
	//to do implementation
//	IME_LOG("playersession get packet size %u", packet.size());
	uint16 opcode = packet.GetOpcode();
	if (GetUserStatus() != E_STATUS_AUTHED)
	{
		//如果还没有验证通过 则只有少数几个协议处理
		switch(opcode)
		{
			case CMD_CS_TEST:
				HandlerEcho(packet);
				break;
			//case CMD_CS_AUTH:
			//	HandlerClientAuth(*packet);
			//	break;
			//case CMD_CS_LOGIN:
			//	HandlerClientLogin(*packet);
			//	break;
			//case CMD_CS_FASTLOGIN:
			//	HandlerClientFastLogin(*packet);
			//	break;
			case CMD_CS_OTHERLOGIN:
				HandlerClientOtherLogin(packet);
				break;
			case CMD_CS_STATICS_DATA:
				HandlerStaticsData(packet);
				break;
			default:
				IME_ERROR("client send packet before auth.opcode %d",opcode);

		};
		return;
	}

	if (!m_pRole->IsInitRoleInfo())
	{
		if (opcode == CMD_CS_INIT_ROLE)
		{
			HandlerRoleInitInfo(packet);
		}
		else if (opcode == CMD_CS_STR_DIRTY_CHECK_REQUEST)
		{
			HandlerDirtyWordCheck(packet);	
		}
		else if (opcode == CMD_CS_STATICS_DATA)
		{
			HandlerStaticsData(packet);
		}
		else
		{
			IME_ERROR("now state client must send init role protocol opcode %u", opcode);
			return;
		}
		return;
	}

	OpcodeHandlerFunc pHandlerFunc = FindOpcodeHandlerFunc(opcode);
	if (pHandlerFunc)
	{
		(this->*pHandlerFunc)(packet);
	}
	else
	{
		IME_ERROR("unknow opcode %d",opcode);
	}
}

void CHandlerPlayersession::UnInit()
{
	//to do implementation
//	IME_LOG("playersession uninit");
	Offline();
}

void CHandlerPlayersession::OnTimer(uint32_t interval)
{
	//to do implementation
//	IME_LOG("playersession ontimer %u", interval);
	if (interval == TIMER_1S)
	{
		OnTimer1s();	
	}
	else if (interval == TIMER_5S)
	{
		OnTimer5s();
	}
	else if (interval == TIMER_3MIN)
	{
		OnTimer3min();
	}
}

void CHandlerPlayersession::SendPacketToRelay(WorldPacket *packet, int key)
{
	sSessCtrl->SendToRelay(*packet, key);
}

void CHandlerPlayersession::SendPacket(WorldPacket *packet)
{
	m_pPlayer->SendPacket(packet);
}

void CHandlerPlayersession::SendErrorMsg(uint16 ErrorMsgNum, uint16 wCmd)
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

bool CHandlerPlayersession::RoleChgClientAndCloseSocket(CHandlerPlayersession* pSess)
{
	IME_ERROR("DUPLICATE LOGIN[UserId=%u ]", GetAccountId());
	if (!m_pRole)
	{
		IME_ERROR("ERROR ROLE IS NULL");
		return false;
	}
	pSess->SetRole(m_pRole);
	m_pRole = NULL;
	WorldPacket info(CMD_SC_CLOSE_CONNECT);
	SendPacket(&info);
	WorldPacket info2(CMD_SC_ERROR_MSG);
	info2 << (uint16_t) ERRNO_MSG_SAME_ACCOUNT_LOGIN;
	SendPacket(&info2);
	m_pPlayer->CloseSocket();
	IME_ERROR("CHG ROLE CLIENT[UserId=%u]", GetAccountId());
	return true;
}

void CHandlerPlayersession::SetRole(CRole* pRole)
{
	pRole->SetSess(this);
	m_pRole = pRole;
}

void CHandlerPlayersession::Online()
{
	if (m_pRole)
	{
		m_pRole->Online();
	}
}
void CHandlerPlayersession::Offline()
{
	if (m_pRole)
	{
		m_pRole->Offline();
		uint32_t interval = getMSTime() - m_dwBeatTime;
		IME_LOG("now %lu last %u", getMSTime(), m_dwBeatTime);
		IME_LOG("ttl [%u] ip [%s] account [%u] offline", interval, GetRemoteIP().c_str(), m_pRole->GetdwAccountId());
	}
	else
	{
		IME_LOG("now %lu last %u", getMSTime(), m_dwBeatTime);
		uint32_t interval = getMSTime() - m_dwBeatTime;
		IME_LOG("ttl [%u] ip [%s] offline", interval, GetRemoteIP().c_str());
	}
}
void CHandlerPlayersession::OnTimer1s()
{
	if (m_pRole)
	{
		m_pRole->OnTimer1s();
	}
}
void CHandlerPlayersession::OnTimer5s()
{
	if (m_pRole)
	{
		m_pRole->OnTimer5s();
	}
}

void CHandlerPlayersession::OnTimer3min()
{
	if (m_pRole)
	{
		m_pRole->OnTimer3min();
	}
	WorldPacket info(CMD_SC_HEARTBEAT);
	info << (uint32_t) getMSTime();
	SendPacket(&info);
	m_dwBeatTime = getMSTime();
}

CHandlerPlayersession::OpcodeHandlerFunc CHandlerPlayersession::FindOpcodeHandlerFunc(uint16 opcode)
{
	OpcodeHandlerMap::iterator itr = m_mapOpcodeHandlerFuncs.find(opcode);
	if (itr != m_mapOpcodeHandlerFuncs.end())
	{
		return itr->second;
	}
	return NULL;
}

void CHandlerPlayersession::OpRelayPacket(uint16 wCmd, WorldPacket& pkg)
{
	MapOpRelayPacket::iterator it = m_mapOpRelayPacketFun.find(wCmd);
	if (it == m_mapOpRelayPacketFun.end())
	{
		IME_ERROR("ERROR RELAY CMD[Cmd=%u]", wCmd);
		return;
	}
	(this->*(it->second))(pkg);
}

void CHandlerPlayersession::InitOpRelayPacket()
{
	m_mapOpRelayPacketFun.clear();
	/////////
	//todo
}

void CHandlerPlayersession::InitOpcodeHandler()
{
	m_mapOpcodeHandlerFuncs.clear();
	
	/////////////////////////////////////
	m_mapOpcodeHandlerFuncs[CMD_CS_TEST] = &CHandlerPlayersession::HandlerEcho;
	m_mapOpcodeHandlerFuncs[CMD_CS_GM_CMD] = &CHandlerPlayersession::HandlerGM;
//	m_mapOpcodeHandlerFuncs[CMD_CS_AUTH] = &CHandlerPlayersession::HandlerClientAuth;
//	m_mapOpcodeHandlerFuncs[CMD_CS_LOGIN] = &CHandlerPlayersession::HandlerClientLogin;
//	m_mapOpcodeHandlerFuncs[CMD_CS_FASTLOGIN] = &CHandlerPlayersession::HandlerClientFastLogin;
	m_mapOpcodeHandlerFuncs[CMD_CS_OTHERLOGIN] = &CHandlerPlayersession::HandlerClientOtherLogin;
//	m_mapOpcodeHandlerFuncs[CMD_CS_CHANGE_PWD] = &CHandlerPlayersession::HandlerChangePwd;
	m_mapOpcodeHandlerFuncs[CMD_CS_STR_DIRTY_CHECK_REQUEST] = &CHandlerPlayersession::HandlerDirtyWordCheck;
	m_mapOpcodeHandlerFuncs[CMD_CS_WORLD_BROADCAST_REQUEST] = &CHandlerPlayersession::HandlerWorldBroadCast;
	m_mapOpcodeHandlerFuncs[CMD_CS_HEARTBEAT] = &CHandlerPlayersession::HandlerHeartBeat;
	m_mapOpcodeHandlerFuncs[CMD_CS_STATICS_DATA] = &CHandlerPlayersession::HandlerStaticsData;
	m_mapOpcodeHandlerFuncs[CMD_CS_EQUIP_OPT] = &CHandlerPlayersession::HandlerEquipOpt;
	m_mapOpcodeHandlerFuncs[CMD_CS_HERO_CHANGE] = &CHandlerPlayersession::HandlerHeroChange;
	m_mapOpcodeHandlerFuncs[CMD_CS_ITEM_COMBINE] = &CHandlerPlayersession::HandlerItemCombine;
	m_mapOpcodeHandlerFuncs[CMD_CS_TASK_COMBAT_PREVIEW] = &CHandlerPlayersession::HandlerTaskCombatPreview;
	m_mapOpcodeHandlerFuncs[CMD_CS_TASK_COMBAT] = &CHandlerPlayersession::HandlerTaskCombat;
}

void CHandlerPlayersession::UserAuthed(uint32 accountId, const std::string & strAccount)
{
	m_dwAccountId = accountId;
	m_strAccount = strAccount;
	IME_LOG("account %d, user id %s", accountId, strAccount.c_str());
	CHandlerPlayersession* pSess = sWorld->FindSess(accountId);

	if (GetToken() != "")
	{
		const RoleBase *pBase = sWorld->GetRoleBase(accountId);
		if (!(pBase && pBase->strToken == GetToken()))
		{
			SendAuthInfo(ERRNO_MSG_AUTH_TOKEN);
			return;
		}
	}
	if (m_pRole != NULL)
	{
		SendAuthInfo(ERRNO_MSG_AUTH_LOGINOUT);
		return;
	}

	/*if (pSess)
	{
		IME_ERROR("ROLE OLG %p %p", pSess->GetRole(), m_pRole);
	}*/
	if (!pSess)
	{
		m_pRole = new CRole(this);
		assert(m_pRole);

		INIT_PROCESS_TIMER;
		PROCESS_TIMER_START;
		if (!m_pRole->Init(m_dwAccountId,strAccount))
		{
			IME_ERROR("role init fetal error");
			m_pRole->SetInitError();
			delete m_pRole;
			m_pRole = NULL;
			return ;
		}
		PROCESS_TIMER_END("init");

		PROCESS_TIMER_START;
		if (GetToken() != "")
		{
			m_pRole->SetbyNoSendLoginData(1);
		}
		else
		{
			m_pRole->SetstrToken(CUtil::GetRandString("t", 32));
		}
		m_pRole->Online();
		if (GetToken() != "")
		{
			m_pRole->SetbyNoSendLoginData(0);
		}
		PROCESS_TIMER_END("online");
	}
	else if (pSess->GetRole() == m_pRole)
	{
		//m_pRole->SendLoginData();
		//m_pRole->Offline();
		//m_pRole->Online();
		IME_LOG("SAME ROLE[UserId=%u]", accountId);
	}
	else if (pSess->RoleChgClientAndCloseSocket(this))
	{
//		m_pRole->SendLoginData();
		m_pRole->Offline();
		if (GetToken() != "")
		{
			m_pRole->SetbyNoSendLoginData(1);
		}
		else
		{
			m_pRole->SetstrToken(CUtil::GetRandString("t", 32));
		}
		m_pRole->Online();
		if (GetToken() != "")
		{
			m_pRole->SetbyNoSendLoginData(0);
		}
	}
	else
	{
		IME_ERROR("CHG ROLE LOGIC ERROR[CharacterId=%u]", accountId);
		return;
	}
	m_eUserStatus = E_STATUS_AUTHED; 
}

void CHandlerPlayersession::CharacterCreate(uint64 account_id, uint32 &character_id, uint16 serverid)
{
	QueryResult *result = LoginDatabase.PQuery(
			"select character_id from character_info where user_id = '%lld' and area_id = %d",
			account_id, serverid
			);
	if (result)
	{
		//todo
		Field *fields = result->Fetch();
		character_id = fields[0].GetUInt32();
		delete result;
		CenterDBCtrl::InsertRePassport(account_id, character_id, serverid);
		return;
	}
//	else
//	{
//		LoginDatabase.PExecute(
//				"insert into character_info(user_id, area_id) values(%lld, %d)",
//				account_id, serverid
//				);
//		QueryResult *next = LoginDatabase.PQuery(
//				"select character_id from character_info where user_id = '%lld' and area_id = %d",
//				account_id, serverid
//				);
//		if (!next)
//			return;
//		Field *fields = next->Fetch();
//		character_id = fields[0].GetUInt32();
//		delete next;
//
//		CenterDBCtrl::InsertRePassport(account_id, character_id, serverid);
//
//		return;
//	}
}

std::string CHandlerPlayersession::GetRemoteIP()
{
	return m_strIp;
}

void CHandlerPlayersession::HandlerChangePwd(WorldPacket &packet)
{
	std::string strPwdOld;
	std::string strPwdNew;
	packet >> strPwdOld;
	packet >> strPwdNew;
	if (strPwdNew.size() == 0 || strPwdNew.size() > E_MAX_USERNAME_PWD_LEN)
	{    
		SendChangePwdResult(ERRNO_MSG_CHANGE_PWD_FAILED);
		return ;
	}    

	LoginDatabase.escape_string(strPwdOld);
	LoginDatabase.escape_string(strPwdNew);
	QueryResult *result = LoginDatabase.PQuery(
			"select user_id,pwd from user_center where user_id = '%s'",
			m_pRole->GetstrAccount().c_str()
			);   
	if (result)
	{    
		Field *fields = result->Fetch();
		std::string strPwdReal = fields[1].GetString();
		if (strPwdReal.length() != 0 && strPwdReal != strPwdOld)
		{    

			SendChangePwdResult(ERRNO_MSG_WRONG_PWD);
			delete result;
			return ;
		}    

		LoginDatabase.PExecute(
				"update user_center set pwd='%s' where user_id='%s'",
				strPwdNew.c_str(), m_pRole->GetstrAccount().c_str()
				);   

		delete result;
		IME_LOG("CHANGE PASSWORD [UserId=%s character=%u]", m_pRole->GetstrAccount().c_str(), m_pRole->GetdwAccountId());
		SendChangePwdResult(ERRNO_MSG_SUCC);
		return;
	}    
	else 
	{
		IME_ERROR("cannot find user when change pwd [CharacterId =%u Account=%s]",
				m_pRole->GetdwAccountId(), m_pRole->GetstrAccount().c_str());
	}
	SendChangePwdResult(ERRNO_MSG_CHANGE_PWD_FAILED);
}

///////////////////////////
void CHandlerPlayersession::HandlerEcho(WorldPacket & packet)
{
	WorldPacket data(CMD_SC_TEST, packet.size());
//	std::string strData;
//	packet >> strData;
//	data << strData;
	data.append(packet.contents(), packet.size());
	SendPacket(&data);
	IME_CHAR_LOG(0, "ACTION", "desc=[echo test]");
	//printf("recv CMD_SC_TEST : %s\n",strData.c_str());
}

//CMD_CS_AUTH 客户端请求认证
void CHandlerPlayersession::HandlerClientAuth(WorldPacket & packet)
{
	std::string strAccount;
	uint32 dwAccountId;
	packet >> dwAccountId;
	
	IME_CHAR_LOG(0, "ACTION", "desc=[client login auth userid %u]", dwAccountId);
	strAccount = "tmp";
	m_dwAccountId = dwAccountId;

	if (dwAccountId == 0)
	{
		IME_ERROR("m_dwAccountId == 0 NewUserData error");
		return;
	}

//	m_dwAccountId = CDBCtrl::GetUserId(strAccount);
//	if (m_dwAccountId == 0)
//	{
//		m_dwAccountId = CDBCtrl::NewUserData(strAccount);
//
//	}
//	if (m_dwAccountId)
//	{
		//todo
		UserAuthed(m_dwAccountId,strAccount);
        return;
//	}
//	else
//	{
//		IME_ERROR("m_dwAccountId == 0 NewUserData error");
//	}
}

void CHandlerPlayersession::HandlerClientLogin(WorldPacket & packet)
{
	uint32 dwVersion;
	std::string strAccount;
	std::string strPwd;
	std::string strUid;
	uint16 wChannel;
//	uint8 flag;
	uint16 serverid;
	packet >> strUid;
	packet >> dwVersion;
	packet >> strAccount;
	packet >> strPwd;
	packet >> wChannel;
//	packet >> flag;
	packet >> serverid;

	IME_ERROR("no use for this protocol");
	return;

	if (dwVersion != INNER_VERSION)
	{
		SendAuthInfo(ERRNO_MSG_AUTH_WRONG_VERSION);
		return ;
	}
	if (!sWorld->IsTarget(serverid))
	{
		IME_ERROR("choose serverid is not server owned, serverid %u", serverid);
		SendAuthInfo(ERRNO_MSG_AUTH_NO_SERVER);
		return;	
	}
//	if (!flag)
//	{
		if (!CDBCtrl::IsCanLogin(serverid))
		{
			SendAuthInfo(ERRNO_MSG_AUTH_NO_SERVER);
			return;
		}
//	}


	//验证帐号密码 gameserver也验证
	if (strAccount.size() == 0 || strAccount.size() > E_MAX_USERNAME_PWD_LEN)
	{
		SendAuthInfo(ERRNO_MSG_AUTH_NAME_LEN);
		return ;
	}
	if (strPwd.size() == 0 || strPwd.size() > E_MAX_USERNAME_PWD_LEN)
	{
		SendAuthInfo(ERRNO_MSG_AUTH_PWD_LEN);
		return ;
	}
//	if (!(wChannel == E_CHANNEL_IOS || wChannel == E_CHANNEL_ANDROID || wChannel == E_CHANNEL_WIN))
//	{
//		SendAuthInfo(ERRNO_MSG_AUTH_CHANNEL);
//		return ;
//	}

	LoginDatabase.escape_string(strAccount);
//	LoginDatabase.escape_string(strPwd);
//	LoginDatabase.escape_string(strUid);
	QueryResult *result = LoginDatabase.PQuery(
			"select user_id,pwd,uid,isauto from user_center where account = '%s' and channel = %d",
			strAccount.c_str(), wChannel
			);
	uint64 accountId = 0;
	if (result)
	{
		//todo
		Field *fields = result->Fetch();
		accountId = fields[0].GetUInt64();
		std::string strPwdReal = fields[1].GetString();
		std::string strUidReal = fields[2].GetString();
		int nIsAuto = fields[3].GetInt32();
		delete result;

		if (nIsAuto && strPwdReal.length() == 0)
		{
			//自动生成的帐号 并且没有修改过密码
			{
				SendAuthInfo(ERRNO_MSG_AUTH_NO_PWD);
				return ;
			}
		}
		else
		{
			//
			if (strPwdReal == strPwd)
			{
				//create character info
				uint32_t character_id = 0;
				CharacterCreate(accountId, character_id, serverid);
				if (character_id == 0)
				{
					SendAuthInfo(ERRNO_MSG_AUTH_SYS);
					return;
				}
				UserAuthed(character_id, CUtil::Uint64ToString(accountId));
				return;
			}
			else
			{
				//密码不正确
				SendAuthInfo(ERRNO_MSG_AUTH_WRONG_PWD);
			}
		}
	}
	else
	{
		//没有该用户
		SendAuthInfo(ERRNO_MSG_AUTH_NO_ACCOUNT);
	}
}

void CHandlerPlayersession::HandlerClientFastLogin(WorldPacket &packet)
{
	std::string strUid;
	uint32 dwVersion;
	std::string strName;
	std::string strPwd;
	uint16 wChannel;
//	uint8 flag;
	uint16 serverid;
	packet >> strUid;
	packet >> dwVersion;
	packet >> strName;
	packet >> strPwd;
	packet >> wChannel;
//	packet >> flag;
	packet >> serverid;

	IME_ERROR("no use for this protocol");
	return;

	if (dwVersion != INNER_VERSION)
	{
		SendAuthInfo(ERRNO_MSG_AUTH_WRONG_VERSION);
		return ;
	}
	if (!sWorld->IsTarget(serverid))
	{
		IME_ERROR("choose serverid is not server owned, serverid %u", serverid);
		SendAuthInfo(ERRNO_MSG_AUTH_NO_SERVER);
		return;	
	}
//	if (!flag)
//	{
		if (!CDBCtrl::IsCanLogin(serverid))
		{
			SendAuthInfo(ERRNO_MSG_AUTH_NO_SERVER);
			return;
		}
//	}
//	if (!(wChannel == E_CHANNEL_IOS || wChannel == E_CHANNEL_ANDROID || wChannel == E_CHANNEL_WIN))
//	{
//		SendAuthInfo(ERRNO_MSG_AUTH_CHANNEL);
//		return ;
//	}
	LoginDatabase.escape_string(strUid);
	QueryResult *result = LoginDatabase.PQuery(
			"select user_id,account,pwd,uid,isauto from user_center where uid = '%s' and channel = %d and isauto = 1",
			strUid.c_str(), wChannel
			);


	if (result)
	{
		//有
		Field *fields = result->Fetch();
		uint32 accountId = fields[0].GetUInt64();
		delete result;

		uint32_t character_id = 0;
		CharacterCreate(accountId, character_id, serverid);
		if (character_id == 0)
		{
			SendAuthInfo(ERRNO_MSG_AUTH_SYS);
			return;
		}
		UserAuthed(character_id, CUtil::Uint64ToString(accountId));
		return;
	}
	else
	{
		SendAuthInfo(ERRNO_MSG_AUTH_NO_ACCOUNT);
	}
}

void CHandlerPlayersession::HandlerClientOtherLogin(WorldPacket &packet)
{
	std::string strUid;
	uint32 dwVersion;
	std::string strName;
	std::string strPwd;
	uint16 wChannel;
	uint8 flag;
	uint16 serverid;
	std::string token;

	packet >> strUid;
	packet >> dwVersion;
	packet >> strName;
	packet >> strPwd;
	packet >> wChannel;
	packet >> serverid;
	packet >> flag;
	packet >> token;

	INIT_PROCESS_TIMER;
	PROCESS_TIMER_START;

	IME_LOG("serverid %u", serverid);
	IME_LOG("struid %s version %u strname %s passwd %s channel %u serverid %u", strUid.c_str(), dwVersion, strName.c_str(), strPwd.c_str(), wChannel, serverid);
	IME_CHAR_LOG(0, "ACTION", "desc=[uid %s login channel %u serverid %u]", strUid.c_str(), wChannel, serverid);
	PACKET_REMAIN_CHECK(packet, CMD_SC_AUTH_RESULT);

	if (dwVersion != INNER_VERSION)
	{
		SendAuthInfo(ERRNO_MSG_AUTH_WRONG_VERSION);
		return ;
	}
	if (!sWorld->IsTarget(serverid))
	{
		IME_ERROR("choose serverid is not server owned, serverid %u", serverid);
		SendAuthInfo(ERRNO_MSG_AUTH_NO_SERVER);
		return;	
	}

//	if (!flag)
//	{
//		if (!CDBCtrl::IsCanLogin(serverid))
//		{
//			SendAuthInfo(ERRNO_MSG_AUTH_NO_SERVER);
//			return;
//		}
//	}
//	if (!(wChannel == E_CHANNEL_IOS || wChannel == E_CHANNEL_ANDROID || wChannel == E_CHANNEL_WIN))
//	{
//		SendAuthInfo(ERRNO_MSG_AUTH_CHANNEL);
//		return ;
//	}
	LoginDatabase.escape_string(strUid);
	LoginDatabase.escape_string(strName);
	QueryResult *result = NULL;
	if (wChannel >= CHANNEL_MIN && wChannel <= CHANNEL_MAX)
	{
		result = LoginDatabase.PQuery(
				"select user_id,account,pwd,uid,isauto,mail,token,reg_ip,reg_device,reg_device_type,last_login_time from user_center where account = '%s' and channel >= %d and channel <= %d",
				strName.c_str(), CHANNEL_MIN, CHANNEL_MAX
				);
	}
	else if (wChannel >= CHANNEL_MIN2 && wChannel <= CHANNEL_MAX2)
	{
		result = LoginDatabase.PQuery(
				"select user_id,account,pwd,uid,isauto,mail,token,reg_ip,reg_device,reg_device_type,last_login_time from user_center where account = '%s' and channel >= %d and channel <= %d",
				strName.c_str(), CHANNEL_MIN2, CHANNEL_MAX2
				);
	}
	else if (wChannel >= CHANNEL_MIN3 && wChannel <= CHANNEL_MAX3)
	{
		result = LoginDatabase.PQuery(
				"select user_id,account,pwd,uid,isauto,mail,token,reg_ip,reg_device,reg_device_type,last_login_time from user_center where account = '%s' and channel >= %d and channel <= %d",
				strName.c_str(), CHANNEL_MIN3, CHANNEL_MAX3
				);
	}
	else
	{
		result = LoginDatabase.PQuery(
				"select user_id,account,pwd,uid,isauto,mail,token,reg_ip,reg_device,reg_device_type,last_login_time from user_center where account = '%s' and channel = %d",
				strName.c_str(), wChannel
				);
	}


	if (result)
	{
		//有
		//验证成功 版本比对 选择服务器
		Field *fields = result->Fetch();
		uint64 accountId = fields[0].GetUInt64();
		std::string passwd = fields[2].GetCppString();
		std::string uid = fields[3].GetCppString();	
		uint16 IsAuto = fields[4].GetUInt8();
		std::string mail = fields[5].GetCppString();
		std::string token = fields[6].GetCppString();
		std::string regip = fields[7].GetCppString();
		std::string regdevice = fields[8].GetCppString();
		std::string regdevicetype = fields[9].GetCppString();
		uint32 lastlogintime = fields[9].GetUInt32();

		m_strToken = token;

		CenterDBCtrl::InsertOrUpdatePassportInfo(accountId, strName, passwd, mail, uid, token, wChannel, regip, regdevice, regdevicetype, E_LOGIN_AUTH_TYPE_PLATFORM, lastlogintime);
		delete result;

		if (IsAuto)
		{
			uint32_t character_id = 0;
			CharacterCreate(accountId, character_id, serverid);
			if (character_id == 0)
			{
				IME_ERROR("accountid %llu, serverid %u", (long long unsigned)accountId, serverid);
				SendAuthInfo(ERRNO_MSG_AUTH_NO_ACCOUNT);
				return;
			}

			SServerData server = sWorld->GetServerList()[serverid];
			if (!flag && server.status == E_AREA_STATUS_STOP)
			{
				if (!sWorld->IsWhiteList(character_id))
				{
					SendAuthInfo(ERRNO_MSG_AUTH_NO_SERVER);
					return;
				}
			}
			PROCESS_TIMER_END("create account");
			uint32_t status = 0;
			const RoleBase *p = sWorld->GetRoleBase(character_id);
			if (p)
				status = p->byStatus;
			if(IS_LIMIT_LOGIN(status) && !flag){
				SendAuthInfo(ERRNO_MSG_AUTH_LIMIT);
				return;
			}
			PROCESS_TIMER_START;
			UserAuthed(character_id, CUtil::Uint64ToString(accountId));
			PROCESS_TIMER_END("userauth");
			m_wChannel = wChannel;
		}
		else
		{
			SendAuthInfo(ERRNO_MSG_AUTH_UNVALID);
		}
		return;
	}
	else
	{
		//没有需要生成
		IME_ERROR("account %s, channel %u", strName.c_str(), wChannel);
		SendAuthInfo(ERRNO_MSG_AUTH_NO_ACCOUNT);
		return;
	}
}

void CHandlerPlayersession::HandlerGM(WorldPacket & packet)
{
	std::string strAccount;
	packet >> strAccount;

        m_pRole->OnGMCmd(strAccount); 
}

void CHandlerPlayersession::HandlerRoleInitInfo(WorldPacket &packet)
{
	m_pRole->HandlerInitRole(packet);
}

void CHandlerPlayersession::HandlerDirtyWordCheck(WorldPacket &packet)
{
	std::string str;
	packet >> str;
	PACKET_REMAIN_CHECK(packet, CMD_SC_STR_DIRTY_CHECK_RESULT);
	if (CNameChecker::IsDirtyWord(str))
	{
		WorldPacket info(CMD_SC_STR_DIRTY_CHECK_RESULT);
		info << (uint16_t) ERRNO_MSG_STR_HAVE_DIRTY;
		SendPacket(&info);
		return;
	}
	if (sWorld->IsExists(str))
	{
		WorldPacket info(CMD_SC_STR_DIRTY_CHECK_RESULT);
		info << (uint16_t) ERRNO_MSG_USER_NAME_ALREADY_USE;
		SendPacket(&info);
		return;
	}

	WorldPacket info(CMD_SC_STR_DIRTY_CHECK_RESULT);
	info << (uint16) 0;
	SendPacket(&info);
	return;
}


////////////////////////////////////
void CHandlerPlayersession::SendAuthInfo(uint16 errno)
{
	WorldPacket packet(CMD_SC_AUTH_RESULT,2);
	packet << errno;
	SendPacket(&packet);
}
void CHandlerPlayersession::SendChangePwdResult(uint16 wErrno)
{
	WorldPacket packet(CMD_SC_CHANGE_PWD_RESULT);
	packet << wErrno;
	SendPacket(&packet);
}

void CHandlerPlayersession::HandlerWorldBroadCast(WorldPacket &packet)
{
	m_pRole->HandlerWorldBroadCast(packet);
}

void CHandlerPlayersession::HandlerHeartBeat(WorldPacket &packet)
{
	uint32 t;
	packet >> t;
	uint32_t interval = getMSTime() - t;
	IME_LOG("send %u, get %lu", t, getMSTime());
	if (m_pRole)
	{
		IME_LOG("ttl [%u] ip [%s] account [%u]", interval, GetRemoteIP().c_str(), m_pRole->GetdwAccountId());
	}
	else
	{
		IME_LOG("ttl [%u] ip [%s]", interval, GetRemoteIP().c_str());
	}
	return;
}

void CHandlerPlayersession::HandlerStaticsData(WorldPacket &packet)
{
	std::string device;
	std::string devicetype;
	std::string secondchannel;
	std::string deviceUid;
	packet >> m_strlogindevice;
	packet >> m_strlogindevicetype;
	packet >> m_strloginsecondchannel;
	packet >> m_strlogindeviceuid;
}

void CHandlerPlayersession::HandlerEquipOpt(WorldPacket &packet)
{
	m_pRole->HandlerEquipOpt(packet);
}

void CHandlerPlayersession::HandlerHeroChange(WorldPacket &packet)
{
	m_pRole->HandlerEquipOpt(packet);
}

void CHandlerPlayersession::HandlerItemCombine(WorldPacket &packet)
{
	m_pRole->HandlerItemCombine(packet);
}

void CHandlerPlayersession::HandlerTaskCombatPreview(WorldPacket &packet)
{
	m_pRole->GetclsTask()->HandlerCombatPreview(packet);	
}

void CHandlerPlayersession::HandlerTaskCombat(WorldPacket &packet)
{
	m_pRole->GetclsTask()->HandlerCombatResult(packet);
}

CHandlerClientSession::CHandlerClientSession()
{
	m_pRelay = NULL;

	//to do implementation
}

CHandlerClientSession::~CHandlerClientSession()
{

}

void CHandlerClientSession::Process(WorldPacket &packet)
{
	//to do implementation
//	IME_LOG("clientsession get packet size %u", packet.size());
}

void CHandlerClientSession::UnInit()
{
	//to do implementation
//	IME_LOG("clientsession uninit");
}

void CHandlerClientSession::OnTimer(uint32_t interval)
{
	//to do implementation
//	IME_LOG("clientsession ontimer interval %u", interval);
}

void CHandlerClientSession::SendPacket(WorldPacket *packet)
{
	m_pRelay->SendPacket(packet);
}
