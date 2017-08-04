/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月08日 23时12分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Server.h"
#include "WorldRunnable.h"
#include "NetRunnable.h"
#include "RelayClientRunnable.h"
#include "World.h"
#include "DatabaseMysql.h"
#include "miniini/miniini.h"
#include "ShardingDB.h"
#include "GmCmdPro.h"
#include "ConfigData.h"
#include "IDCtrl.h"
#include "Log.h"
//#include "LuaState.h"
//#include "LuaCtrl.h"
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
#include "Role.h"
#include "DynamicStruct.h"
#include "World.h"
#include "CenterDBCtrl.h"
#include "EnumDefines.h"
#include "TileIsometric.h"

extern CShardingDB WorldDb;                ///< Accessor to the sharding world database
extern DatabaseMysql LoginDatabase;        ///< Accessor to the login database
extern DatabaseMysql OperateDatabase;       ///< Accessor to the Operation database

//CLuaState g_luaState;
INIFile g_serverIni;
extern std::string g_strConfigPath;
int g_nVersion;
extern std::string g_strWorldDatabaseName;
extern std::string g_strOperateDatabaseName;

bool gDaemonFlag = false;
volatile bool g_stopEvent = false;

CUserSession *GetSessionSpecial(ZThread::CountedPtr<CNetClient> ptrThis)
{
	 return new CPlayerSession(ptrThis);
}
/*
bool StartDB()
{

	INISection * database = g_serverIni.GetSection("database");
	if (!database)
	{
		IME_ERROR("Miss section [database] in gameserver.ini");
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
*/
bool InitServer()
{
	srand(time(NULL));

	//日志等级
	INISection * configPath = g_serverIni.GetSection("config");
	if (!configPath)
	{
		IME_ERROR("Miss section [config] in config ini");
		return false;
	}
	std::string strLogLevel;
	if (!configPath->ReadString("loglevel",strLogLevel))
	{
		IME_ERROR("Missing loglevel info");
		return false;
	}
	sLog->SetLogLevel((char *)strLogLevel.c_str());

	int debugmask = 0;
	if (!configPath->ReadInt("logdebug", debugmask))
	{
		IME_ERROR("Missing logdebug");
		return false;
	}
	IME_LOG("log debug %x", (unsigned int)debugmask);
	sLog->SetDebugLogMask((DebugLogFilters)debugmask);

	//////////////////////////////////////////////////////////////////////////
	if (!HandlerInit(MAIN_THREAD))
	{
		IME_ERROR("man thread handler init fail");
		return false;
	}
	return true;
}

void EndServer()
{
	HandlerFinally(MAIN_THREAD);
//	CLuaCtrl::UnInit();
//	g_luaState.Destroy();
}

// Handle termination signals
// Put the World::m_stopEvent to 'true' if a termination signal is caught 
void OnSignal(int s)
{
	switch (s)  
	{ 
		case SIGINT: 
		case SIGQUIT: 
		case SIGTERM: 
//		case SIGABRT:
		case SIGUSR1:
			//sWorld->AllOffline();
			g_stopEvent = true;
			break; 
	} 
	signal(s, OnSignal);
}
// Define hook '_OnSignal' for all termination signalsi
void HookSignals()
{    
	signal(SIGINT, OnSignal);
	signal(SIGQUIT, OnSignal);
	signal(SIGTERM, OnSignal);
	signal(SIGABRT, OnSignal);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGUSR1, OnSignal);
}
/// Unhook the signals before leaving
void UnHookSignals()
{    
	signal(SIGINT, 0);
	signal(SIGQUIT, 0); 
	signal(SIGTERM, 0);
	signal(SIGABRT, 0);
	signal(SIGUSR1, 0);
}
void ShowUsage(const char * name)
{
	IME_ERROR("pitayaserver");
	IME_ERROR("Usage: %s [-d] ",name);
	IME_ERROR("-d start as a daemon, default is false");
}
void ParseArg(int argc, char * argv[])
{
	for(int i = 1; i < argc; i += 2)
	{
		if(0 == strcmp(argv[i], "-d"))
		{
			gDaemonFlag = true;
		}
		else
		{
			ShowUsage(argv[0]);
			exit(0);
		}
	}

}
/* 
class CA: public CDynamicStruct
{
	public:
		CA();
        uint32_t m_dwObjId;
        uint8_t m_byType;
        uint32_t m_dwIndex;
        uint8_t m_byAttribute; //卡牌属性
        uint8_t m_byStarLevel; //卡牌星级
        uint16_t m_wLevel; //卡牌等级
        uint32_t m_dwExp; //卡牌经验
        uint32_t m_dwExpLimit; //下一级升级上限
        uint32_t m_dwEffectIndex;
        uint32_t m_dwAttackSkillIndex;
        uint32_t m_dwDeffenseSkillIndex;
        uint32_t m_byRare;
		uint32_t m_dwLastExpLimit;
		uint32_t m_byFlag;
		uint32_t m_dwAttack;
		uint32_t m_dwDefence;
		uint32_t m_dwHealth;
		uint32_t m_dwAttackGrow;
		uint32_t m_dwDefenceGrow;
		uint32_t m_dwHealthGrow;
		uint32_t m_dwExpGrow;
		uint32_t m_dwCritRate;
//		uint32_t m_dwDodgeRate;
//		uint32_t m_dwAction;
		uint32_t m_dwSuitIndex;
		uint32_t m_dwSkillPara;
//		uint32_t m_dwInitSkillIndex;
//		uint32_t m_dwStudySkillIndex;
		uint32_t m_dwMasterSkillIndex;
		uint16_t m_wMasterSkillLv;
		uint32_t m_dwSkillIndex;			
		uint32_t m_dwGrowLimit;
		uint32_t m_dwLimitBreakNumber;
		uint32_t m_dwLimitBreak;
		uint32_t m_dwLimitBreakPro;
		uint32_t m_dwAwakePro;
		uint32_t m_dwAddExp;
		uint32_t m_dwConsumeCoin;
		uint32_t m_dwGetCoin;
		uint32_t m_dwBreakExp;
		uint8_t m_byMultiPower;
		uint32_t m_dwMultiTime;
		uint32_t m_dwTotalConsumeCoin;
		uint32_t m_dwSkillPro;
		uint32_t m_dwSkillPower;
		uint32_t m_dwDurationExp;
		uint32_t m_dwDurationCoin;
		uint32_t m_dwObjDrop;
		uint32_t m_dwStrengthRecover;
		uint32_t m_dwEnergyRecover;
		uint32_t m_dwAddHarm;
		uint32_t m_dwReduceHarm;
		uint32_t m_dwAddCritHarm;
		uint16_t m_wLeaderLevel;
		uint32_t m_dwLeaderIndex;
		uint32_t m_dwCardGroup;
		uint32_t m_dwMasterIndex;
		uint16_t m_wAttackPlus;
		uint16_t m_wDefencePlus;
		uint16_t m_wHealthPlus;

		uint32_t m_dwOneLevelExp;
};
*/
//int JudgeWin(CRole *pCRole, CRole *pPeerCRole, std::vector<sCSEffect> &vecEffect, std::vector<sCSEffect> &vecPeerEffect, sCSEffect &sfactor, uint32_t &initattack, uint32_t &initdefence);

void hexdump(const char *p, int len);

void testmap()
{
	std::map<uint32_t, uint32_t> map;
	std::set<uint32_t> set;
	for (int i = 0; i < 50; i++)
	{
		map.insert(std::pair<uint32_t, uint32_t>(i,1));
		set.insert(i);
	}
}
int main(int argc, char * argv[])
{

//	sLog->Initialize();
//
//	if (!g_serverIni.OpenFile("gameserver.ini"))
//	{
//		IME_ERROR("Cannot open gameserver.ini");
//		return 0;
//	}
//
//	if (!InitServer())
//	{
//		IME_ERROR("InitServer failed");
//		return 0;
//	}
//
//	//do many init db here
//	if (!StartDB())
//	{
//		IME_ERROR("StartDB failed");
//		return 0;
//	}
//
//	IME_LOG("GameServer Start!");
//	
//	std::string username("test");
//	uint32 userid = CDBCtrl::GetUserId(username);
//	IME_LOG("userid %u", userid);
//	CRole *pRole = new CRole(NULL);
//	pRole->Init(userid, username);
//
//	pRole->GetclsCardPacket()->CopyDataForDuration();
//	std::vector<uint32_t> vecCard, vecIndexs;
//	pRole->GetclsCardPacket()->GetEquipCards(vecCard, vecIndexs);
//	IME_LOG("end test");
//	IME_LOG("attack min %u max %u, defence min %u max %u, attribute %u, attribute2 %u, team %u", pRole->GetdwAttackMin(), pRole->GetdwAttackMax(), pRole->GetdwDefenceMin(), pRole->GetdwDefenceMax(), pRole->GetdwCardAttributes(), pRole->GetdwCardAttributes2(), pRole->GetbyCurrentTeam());


//	CRole *pRole = new CRole(NULL);
//	CRole *pPeerCRole = new CRole(NULL);
//	pRole->LoadDataForDuration(1);
//	pPeerCRole->LoadDataForDuration(4);
//
//	uint32_t initattack,initdefence;
//	pRole->GetclsCardPacket()->CopyDataForDuration();
//	pPeerCRole->GetclsCardPacket()->CopyDataForDuration();
//	std::vector<sCSEffect> vec, vecPeer;
//	sCSEffect sfactor;
//	int ret = JudgeWin(pRole, pPeerCRole, vec, vecPeer, sfactor, initattack, initdefence);
	
//	printf("1 max exp is %u, 2 max exp is %u", CConfCardUp::GetMaxExp(1), CConfCardUp::GetMaxExp(2));
//	printf("3 star exp0's level is %u, exp4's level is 3 %u,4 %u,5 %u,  exp555's level is %u, exp554'level is %u, exp556'level is %u", CConfCardUp::FindLevel(3, 0), CConfCardUp::FindLevel(3, 3), CConfCardUp::FindLevel(3, 4), CConfCardUp::FindLevel(3, 5), CConfCardUp::FindLevel(3, 555), CConfCardUp::FindLevel(3, 554), CConfCardUp::FindLevel(3, 556));

//	CRole *pRole = new CRole(NULL);
//	pRole->LoadDataForDuration(1);

//	IME_LOG("start");
//	IME_LOG("1st");
//	pRole->GetclsCardPacket()->Cal1stTeam();
//	IME_LOG("2nd");
//	pRole->GetclsCardPacket()->Cal2ndTeam();
//	IME_LOG("end");

//	IME_LOG("start");
//	pRole->GetclsCardPacket()->Dumpdata();
//	CJewelSkill::JewelSkillAttack(pRole, 2, 1, 1, 20);
//	pRole->GetclsCardPacket()->Dumpdata();
//	pRole->GetclsCardPacket()->Dumpdata();
//	CJewelSkill::JewelSkillDefence(pRole, 2, 1, 1, 30);
//	CJewelSkill::JewelSkillAttackHigh(pRole, 2, 1, 2, 30);
//	CJewelSkill::JewelSkillAttackLow(pRole, 2, 1, 2, 30);
//	CJewelSkill::JewelSkillDefenceHigh(pRole, 2, 1, 2, 30);
//	CJewelSkill::JewelSkillDefenceLow(pRole, 2, 1, 2, 30);
//	CJewelSkill::JewelSkillAttackHighPro(pRole, 2, 1, 2, 50);
//	CJewelSkill::JewelSkillDefenceHighPro(pRole, 2, 1, 2, 50);
//	CJewelSkill::JewelSkillSkillPro(pRole, 2, 1, 2, 50);
//	pRole->GetclsCardPacket()->Dumpdata();
//	IME_LOG("end");

//	printf("attr %u\n", *CConfAttributeRestriction::Find(1,0));
//	printf("attr %u\n", *CConfAttributeRestriction::Find(1,1));
//	printf("attr %u\n", *CConfAttributeRestriction::Find(1,2));
//	printf("attr %u\n", *CConfAttributeRestriction::Find(1,3));
//	printf("attr %u\n", *CConfAttributeRestriction::Find(4,2));
//	printf("attr %u\n", *CConfAttributeRestriction::Find(6,7));

//	CRole *pRole = new CRole(NULL);
//	CRole *pPeerCRole = new CRole(NULL);
//	pRole->LoadDataForDuration(1);
//	pPeerCRole->LoadDataForDuration(4);
//	CJewelSkill::JewelSkillAttackHighPro(pRole, 2, 0, 2, 90);
//	CJewelSkill::JewelSkillSkillPro(pRole, 2, 0, 2, 50);
//	pRole->GetclsCardPacket()->CopyDataForDuration();
//	pPeerCRole->GetclsCardPacket()->CopyDataForDuration();

//	pRole->GetclsCardPacket()->Dumpdata();
//	pPeerCRole->GetclsCardPacket()->Dumpdata();
//
//	uint32_t pro;
//	int32_t para1, para2;
//	pro = 80;
//	para1 = 1;
//	para2 = 20;
//	int ret = CCardSkill::CardSkillAttackBuff(pRole, pPeerCRole, pro, para1, para2); 	
//	int ret = CCardSkill::CardSkillDefenceBuff(pRole, pPeerCRole, pro, para1, para2); 	
//	int ret = CCardSkill::CardSkillDefenceDebuff(pRole, pPeerCRole, pro, para1, para2); 	
//	int ret = CCardSkill::CardSkillIgnoreDefence(pRole, pPeerCRole, pro, para1, para2); 	
//	int ret = CCardSkill::CardSkillChangePeerAttribute(pRole, pPeerCRole, pro, para1, para2); 	
//	pPeerCRole->GetclsCardPacket()->SetLaunchObjid(1);	
//	int ret = CCardSkill::CardSkillAttackCrit(pPeerCRole, pRole, pro, para1, para2); 	
//	int ret = CCardSkill::CardSkillAttackDebuff(pRole, pPeerCRole, pro, para1, para2); 	
//	int ret = CCardSkill::CardSkillIgnoreAttack(pRole, pPeerCRole, pro, para1, para2); 	
//	int ret = CCardSkill::CardSkillChangeAttribute(pRole, pPeerCRole, pro, para1, para2); 	
//	pRole->GetclsCardPacket()->SetLaunchObjid(1);	
//	int ret = CCardSkill::CardSkillDefenceCrit(pRole, pPeerCRole, pro, para1, para2); 	
//	int ret = CCardSkill::CardSkillAllAttackBuff(pRole, pPeerCRole, pro, para1, para2); 	
//	int ret = CCardSkill::CardSkillAllDefenceDebuff(pRole, pPeerCRole, pro, para1, para2); 	
//	int ret = CCardSkill::CardSkillAllDefenceBuff(pPeerCRole, pRole, pro, para1, para2); 	
//	int ret = CCardSkill::CardSkillAllAttackDebuff(pRole, pPeerCRole, pro, para1, para2); 	
//	pRole->GetclsCardPacket()->Dumpdata();
//	pPeerCRole->GetclsCardPacket()->Dumpdata();
//	IME_LOG("ret %u effect %u, para1 %u, para2 %u", ret, pro, para1, para2);
//	return 0;

//	CRole *pRole = new CRole(NULL);
//	CRole *pPeerCRole = new CRole(NULL);
//	pRole->LoadDataForDuration(1);
//	pPeerCRole->LoadDataForDuration(4);
//	std::vector<sCSEffect> vec, vecPeer;
//	sCSEffect sfactor;
//	uint32_t initattack,initdefence;
//	IME_LOG("judgewin\n");
//	pRole->GetclsCardPacket()->CopyDataForDuration();
//	pPeerCRole->GetclsCardPacket()->CopyDataForDuration();
////	pRole->GetclsCardPacket()->Dumpdata();
////	pPeerCRole->GetclsCardPacket()->Dumpdata();
//	int ret = JudgeWin(pRole, pPeerCRole, vec, vecPeer, sfactor, initattack, initdefence);
////	pRole->GetclsCardPacket()->Dumpdata();
////	pPeerCRole->GetclsCardPacket()->Dumpdata();
//	IME_LOG("ret %u, initattack %u, initdefence %u", ret, initattack, initdefence);
//	IME_LOG("attack %u, defence %u, attackattr %u, defencearr %u, factor %u", sfactor.attack, sfactor.defence, sfactor.attackattribute, sfactor.defenceattribute, sfactor.Para1);
//	for (int i = 0; i< vec.size(); i++)
//	{
//	IME_LOG("[attack] ojbid %u, skillindex %u, skilleffect %u, para1 %d para2 %d, order %u, attack %u, defence %u, attackattribute %u, defenceattribute %u", vec[i].ObjId, vec[i].SkillIndex, vec[i].SkillEffect, vec[i].Para1, vec[i].Para2, vec[i].Order, vec[i].attack, vec[i].defence, vec[i].attackattribute, vec[i].defenceattribute);
//	}
//	for (int i = 0; i < vecPeer.size(); i++)
//	{
//	IME_LOG("[defence] ojbid %u, skillindex %u, skilleffect %u, para1 %d para2 %d, order %u, attack %u, defence %u, attackattribute %u, defenceattribute %u", vecPeer[i].ObjId, vecPeer[i].SkillIndex, vecPeer[i].SkillEffect, vecPeer[i].Para1, vecPeer[i].Para2, vecPeer[i].Order, vecPeer[i].attack, vecPeer[i].defence, vecPeer[i].attackattribute, vecPeer[i].defenceattribute);
//	}
	
//	CRole *pRole = new CRole(NULL);
//	pRole->LoadDataForDuration(1);
	
//	CTujian *pTujian = new CTujian();
//	pTujian->Init(pRole);
//	pTujian->DirtySaveData();
//	pTujian->AddTujian(1);
//	pTujian->AddTujian(1);
//	pTujian->DirtySaveData();
//	pTujian->DirtySaveData();
//	pTujian->AddTujian(3);
//	pTujian->DirtySaveData();

//	CConfTech::MapData *p = CConfTech::GetMap();			
//	IME_LOG("size %u", p->size());

//	uint32_t user_id, mail_id;
//	user_id = 1;
//	mail_id = 1;
//	// affect row
//	if (!CDBCtrl::UpdateMail(user_id, mail_id))
//	{
//		IME_ERROR("delete mail fail");
//		return;
//	}

//	std::vector<std::string> abc;
//	AnyType abcd(abc, true);
//	printf("*********type %x\n****************", abcd.type());
	
//	printf("%llx\n", (uint64_t) 1 << 32 + 1);
//	uint32_t taskindex = 200104;
//	STC_CONF_MISSION_BASE *p;
//	uint32_t ret;
//	ret = CConfSkillCreate::GetSkillIndex(2);
//	printf("**%d******%u********",ret,  p->dwIndex);

//	CRole *pCRole = new CRole(NULL);
//	pCRole->LoadDataForDuration(11);

//	IME_LOG("*******************************************");
//	STC_CONF_JEWEL_SKILL *pJewelSkill = CConfJewelSkill::Find(10);
//	CJewelSkill::Init();
//	CJewelSkill::JewelSkillFunc pSkillFunc = CJewelSkill::Find(pJewelSkill->wType);
//	if (pSkillFunc == NULL)
//	{
//		return -1;
//	}
//	IME_LOG("jewel skill %u, %u, %u", pJewelSkill->wType, pJewelSkill->para1, pJewelSkill->para2);
//	CJewelSkill::JewelSkillDefence(pCRole, 0, 1, pJewelSkill->para1, pJewelSkill->para2);

//	if ((*pSkillFunc)(pCRole, 0, 1, pJewelSkill->para1, pJewelSkill->para2))
//	{
//		IME_ERROR("jewel skill exec fail index %u", pJewelSkill->dwIndex);
//		return -1;
//	}

//	CRole *pCRole = new CRole(NULL);
//	pCRole->LoadDataForDuration(11);
//	
//	IME_LOG("*******************************************");
//	CShopEffect::SEffect temp;	
//	memset(&temp, 0, sizeof(CShopEffect::SEffect));
//	temp.para1 = 1;
//	CShopEffect::EggEffect(pCRole, temp);
//	temp.para1 = 5;
//	CShopEffect::GiftEffect(pCRole, temp);
//	temp.para1 = 100;
//	CShopEffect::StrengthItemEffect(pCRole, temp);
//	CShopEffect::MissDurationEffect(pCRole, temp);
//	bool ret = CShopEffect::IsFullCardPacketGift(pCRole, 6);
//	printf("ret %d", ret);
//	temp.para1 = 15;
//	temp.para2 = 0;
//	temp.para3 = 0;
//	temp.para4 = 13;
//	CShopEffect::SkillCombineBookEffect(pCRole, 1, 0, temp); 

//	int ret = CDBCtrl::GetStatusArena(8);
//	printf("ret %u", ret);
	
//	CCard tmp;
//	int ret = tmp.CreateCard(1, 1, 1);
//	printf("ret %d\n", ret);

//	CRole *pCRole = new CRole(NULL);
//	pCRole->LoadDataForDuration(1);
//	CRole *pPeerCRole = new CRole(NULL);
//	pPeerCRole->LoadDataForDuration(2);
//	WorldPacket by;
//	uint8_t eva;
//	int ret = DurationJudgeWin(pCRole, pPeerCRole, by, eva);
//	printf("ret %d, eva %u", ret, eva);
//	hexdump(by.contents(), by.size());
//	uint16_t level = CConfMasterLevel::FindLevel(7, 0);
//	printf("%u", level);
//	printf("attr %u\n", *CConfAttributeRestriction::Find(0,5));
	
//	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
//	QueryResult *result = mysql->PQuery(
//			"select max(user_id) "
//			"from user_timer"
//			);
//
//	if (result)
//		Field *fields = result->Fetch();
//		uint32_t id = fields[0];
//	}
//	
//	std::vector<STC_CONF_ROB_ROBOT *>* pVec;	
//	std::vector<STC_CONF_ROB_ROBOT *>::iterator it;
//	std::vector<int> vecRobotId;
//	pVec = CConfRobRobot::GetData(1);
//	for (it = pVec->begin(); it != pVec->end(); it++)
//	{
//		uint32_t robotid = (*it)->dwIndex;
//		IME_ERROR("robotid %u", robotid);
//	}
//	uint32_t level = CConfCardUp::FindLevel(1, 0, 100);
//	CCard card;
//
//	card.CreateCard(1, 2, 1);

//	uint16_t level = CConfCardUp::FindLevel(4, 925600, 400);
//	uint32_t exp = 1583256720;
//	uint64_t ret = (uint64_t)exp * 400 / 100.0;
//	STC_CONF_DURATION_MISSION *p = CConfDurationMission::Find(300310);
//	printf("level %llu", p->dwIndex);
//	sWorld->InitSettings();
//	sWorld->GetWorldBoss()->DataDump();
//	sWorld->GetWorldBoss()->GetData(1869639791);
//	sWorld->GetWorldBoss()->AddResidentKey(1869639791);
//	sWorld->GetWorldBoss()->GetData(1969844080);
//	sWorld->GetWorldBoss()->GetData(2036819815);
//	sWorld->GetWorldBoss()->GetData(1634952294);
//	sWorld->GetWorldBoss()->ClearResidentKey();
//	sWorld->GetWorldBoss()->GetData(2036819815);
//	sWorld->GetWorldBoss()->DataDump();
//	CRole *p = new CRole(NULL);
//	printf("before delete %p", p);
//	delete p;
//	printf("after delete %p\n", p);
//	uint32_t s = 0;
//	uint32_t d = 3147483648;
//	int cd = s - d;
////	printf("%u %d %u", cd, cd, time(NULL));
//	ByteBuffer by;
////	for (uint32_t i = 0; i < d; i++)
////	{
////		by >> s;
////	}
//
//		std::vector<CDBCtrl::SArena> vecTmp;
//		if (CDBCtrl::GetUserArenaAll(vecTmp))
//		{
//			for (int i = 0; i < vecTmp.size(); i++)
//			{
////				CRole *pCRole = FindUserRole(vecTmp[i].userid);		
//				uint32_t prestige = CArena::GetPrizePrestige(vecTmp[i].rank); 
//				IME_LOG("prestige %u, rank %u, userid %u", prestige, vecTmp[i].rank, vecTmp[i].userid);
////				if (pCRole != NULL)
////				{
////					pCRole->GetclsArena()->SetdwRanked(vecTmp[i].rank);
////					pCRole->GetclsArena()->SetdwGetPrestige(prestige);
////					pCRole->GetclsArena()->HandlerProUpdate();
////				}	
////				else
////				{
//					if (!CDBCtrl::UpdateUserArenaForRankPrestige(vecTmp[i].rank, prestige, vecTmp[i].userid))
//					{
//						IME_ERROR("update arena data fail userid %u", vecTmp[i].userid);
//					}
////				}
//			}
//		}
	
//	int m_dwRank = 5002;
//
//	int interval[ARENA_USER_GET_INTERVAL_MAX][2] = ARENA_USER_GET_INTERVAL;
//	int valarr[ARENA_USER_GET_INTERVAL_MAX] = ARENA_USER_GET_INTERVAL_VAL;
//	int val = valarr[ARENA_USER_GET_INTERVAL_MAX - 1];
//	int valpre = valarr[ARENA_USER_GET_INTERVAL_MAX -1];
//	int rankline = 1;
//	int k = 0;
//	for (k = 0; k < ARENA_USER_GET_INTERVAL_MAX - 1; k++)
//	{
//		if (m_dwRank >= interval[k][0] && m_dwRank <= interval[k][1])
//		{
//			val = valarr[k];
//			break;
//		}	
//	}
//	if (k == 0)
//	{
//		valpre = val;
//	}
//	else
//	{
//		valpre = valarr[k - 1];
//		rankline = interval[k - 1][1];
//	}
//IME_LOG("rank %u int %u lastint %u rankline %u", m_dwRank, val, valpre, rankline);
//
//	int intval = val;
//	int start = m_dwRank + 3 * intval;
//	std::vector<uint32_t> vecRank;
//	int IsOpr = 0;
//	for (int i = 0; i < 11; i++)
//	{
//		vecRank.push_back(start);
//
////		IME_LOG("start %u intval %u rankline %u", start, intval, rankline);
//		if (!IsOpr)
//		{
//			if (start - intval <= rankline)
//			{
//				intval = valpre;
//				start = rankline + intval;
////				IME_LOG("start %u intval %u", start, intval);
//				IsOpr = 1;
//			}
//		}
//
//		start -= intval;
//
//		if (start <= 0)
//			break;
//	}
//
//	for (int i = 0; i < vecRank.size(); i++)
//	{
//		IME_LOG("%u, rank %u", i, vecRank[i]);	
//	}

//	uint32_t m_dwLuck = 501;
//	uint16_t viplv = 7;
//	STC_CONF_VIP *pVipConf = CConfVip::Find(viplv);
//	if (pVipConf == NULL)
//	{
//		IME_ERROR("vip lv %u can not find in vip csv", viplv);
//	}
//	else
//	{
//		uint32_t everyluck = pVipConf->dwLuckEveryGet; 
//		uint32_t maxluck = pVipConf->dwLuckMax;
//		printf("luck every luck %u, luckmax %u", everyluck, maxluck);	
//		uint32_t tmpluck = m_dwLuck + everyluck;
//		if (m_dwLuck < maxluck)
//		{
//			m_dwLuck = tmpluck;
//			if (m_dwLuck > maxluck)
//				m_dwLuck = maxluck;
//			printf("now luck %u", m_dwLuck);
//		}
//	}
//			printf("now luck %u", m_dwLuck);

//	uint32_t dollar = 10;
//	uint16_t oldviplv = 0;
//	uint32_t oldluck = 0;
//
//	uint32_t luck = oldluck + dollar * DOLLAR_LUCK_PARA;
//	uint16_t newviplv = 1;
//	STC_CONF_VIP *pVipConf = CConfVip::Find(newviplv);
//if (newviplv > oldviplv)
//{
//	if (pVipConf == NULL)
//	{
//		IME_ERROR("vip lv %u can not find in vip csv", newviplv);
//	}
//	else
//	{
//		luck = pVipConf->dwLuckMax + dollar * DOLLAR_LUCK_PARA;
//	}
//}
//	printf("luck is %u", luck);

//	uint16 viplevel = 10;
//	uint32 luck = 0;
//	STC_CONF_GACHA *pConf = NULL;
////	pConf = CConfGacha::GetByChargeGacha();
//	pConf = CConfGacha::GetByVipFirstGacha(viplevel);
//	printf("===================");
//	pConf = CConfGacha::GetByVipNormalGacha(viplevel, luck);

//	if (CUtil::RandEither(1000, 10000))  
//	{                                       
//		IME_LOG("happen boss");             
//	}
//	IME_ERROR("===================");
//	std::map<uint32_t, uint32_t> map;
//	uint32_t total = 0;
//	for (int i = 0; i < 100000; i++)
//	{
//		STC_CONF_UNIQUE_COLLECTION* pRand = CConfUniqueCollection::GetRandResult(43);
//		map[pRand->wWeight]++;	
//		total++;
//	}
//	IME_ERROR("===================");
//	for (std::map<uint32_t, uint32_t>::iterator it = map.begin(); it != map.end(); it++)
//	{
//		IME_ERROR("weight %u count %u percent %f %%", it->first, it->second, it->second * 100.0 / total);
//	}
	
//	INIT_PROCESS_TIMER;
//	PROCESS_TIMER_START;
//	CCard *pCard = NULL;
//	for (int i = 0; i < 100; i++)
//	{
////		pCard = new CCard();	
////		delete pCard;	
//		testmap();
//	}	
//	PROCESS_TIMER_END(1, "new class");
//	std::map<uint32_t, uint8_t> m_mapAllStar;
//	m_mapAllStar[1] = 2;
//	std::map<uint32_t, uint8_t>::iterator it3;                           
//	std::map<uint32_t, CDurationMission::CDurationMission::DMission_t>::iterator it;
//	std::map<uint32_t, CDurationMission::CDurationMission::DMission_t> mapb;
//	mapb[1];
//	mapb[2];
//	mapb[3];
//	mapb[4];
//	mapb[5];
//	it = mapb.end();
//	IME_ERROR("******");
//	for (it3 = m_mapAllStar.begin(); it3 != m_mapAllStar.end(); it++)   
//	{                                                                    
//		IME_ERROR("===============");
//		uint32_t a = it3->first;                                                
//		uint32_t b = it3->second;                                               
//	}                                                                    
	
//		std::map<uint32_t, CDurationMission::DMission_t> m_mapMission; 
//		CRole *m_pCRole;
//		bool m_IsInit;
//		uint32_t m_MissionPosition;
//
//		uint32_t m_HighMissionPosition;
//		uint32_t m_HighMissionPositionLimit;
//		std::map<uint32_t, CDurationMission::DMission_t> m_mapHighMission;
//
//		std::map<uint32_t, CDurationMission::BMission_t> m_mapBranchMission; 
//		
//		std::map<uint32_t, CDurationMission::DMission_t> m_mapActiveMission;
//
//		std::map<uint32_t, uint8_t> m_mapAllStar;
//
////		m_mapMission[30101];
////		m_mapMission[30106];
////		m_mapAllStar[301] = 0;
//
//		ByteBuffer by;
//	std::map<uint32_t, CDurationMission::DMission_t>::iterator it;
//		it = m_mapMission.end();
////	by << m_MissionPosition;
////	by << (uint32_t) m_mapMission.size();
////	std::map<uint32_t, CDurationMission::DMission_t>::iterator it;
////	for (it = m_mapMission.begin(); it != m_mapMission.end(); it++)
////	{
////		by << it->second.Index;
////		by << it->second.Number;
////		by << it->second.FlushTime;
////		by << it->second.MaxEva;
////	}
////	by << (uint32_t) m_mapBranchMission.size();
////	std::map<uint32_t, CDurationMission::BMission_t>::iterator it2;
////	for (it2 = m_mapBranchMission.begin(); it2 != m_mapBranchMission.end(); it2++)
////	{
////		by << it2->second.dwTaskId;
////		by << it2->second.dwTime;
////	}
////
////	by << m_HighMissionPosition;
////	by << m_HighMissionPositionLimit;
////	by << (uint32_t) m_mapHighMission.size();
////	std::map<uint32_t, CDurationMission::DMission_t>::iterator it;
////	for (it = m_mapHighMission.begin(); it != m_mapHighMission.end(); it++)
////	{
////		by << it->second.Index;
////		by << it->second.Number;
////		by << it->second.FlushTime;
////		by << it->second.MaxEva;
////	}
//	it++;
//	by << (uint32_t) m_mapAllStar.size();
//	std::map<uint32_t, uint8_t>::iterator it3;
//	for (it3 = m_mapAllStar.begin(); it3 != m_mapAllStar.end(); it++)
//	{
//		by << it3->first;
//		by << it3->second;
//		IME_ERROR("+++++++++++++++++++++");
//	}
/*
	IME_LOG("================");
	INIT_PROCESS_TIMER;
	PROCESS_TIMER_START;
	for (int i = 0; i < 200; i++)
{
	LoginDatabase.PExecute("update gameserver_info set ip='172.16.1.149', port = 5555, online_num=2, update_time=1392181654, version=8, can_login = 1, status = 3, is_new = 1, server_name = 'å¼<80>å<8f><91>æ<9c><8d>1', domain = '172.16.1.149', res_url = 'http://172.16.1.149/CardResource/8/0-0/res' where area_id=0"
				);
}
	IME_LOG("================");
	PROCESS_TIMER_END(1, "test1");
	PROCESS_TIMER_START;
	for (int i = 0; i < 200; i++)
{
	OperateDatabase.PQuery("select update_time from gameserver_info where server_id=0");
}
	IME_LOG("================");
PROCESS_TIMER_END(1, "test2");
	PROCESS_TIMER_START;
	for (int i = 0; i < 200; i++)
{
	OperateDatabase.PExecute("update gameserver_info set server_name='å¼<80>å<8f><91>æ<9c><8d>1',ip='172.16.1.149',local_ip='172.16.1.149', port=5555, version='8', res_version='', online_num=2, can_login=1, status=3, login_strategy_id=0, res_server_ip='http://172.16.1.149/CardResource/8/0-0/res', update_time=1392181654 where server_id=0"
			);
}
	IME_LOG("================");
PROCESS_TIMER_END(1, "test3");

	PROCESS_TIMER_START;
std::vector<uint8_t> vec;
vec.reserve(445 * 50 * 10);
IME_LOG("vec capacity %u", vec.capacity());
for (int i = 0; i < 445 * 500; i++)
{
	vec.resize(i);
}
IME_LOG("vec capacity %u", vec.capacity());
PROCESS_TIMER_END(1, "reserve resize ");

	PROCESS_TIMER_START;
std::vector<uint8_t> vecb;
IME_LOG("vec capacity %u", vecb.capacity());
for (int i = 0; i < 445 * 500; i++)
{
	vecb.resize(i);
}
IME_LOG("vec capacity %u", vecb.capacity());
PROCESS_TIMER_END(1, "no reserve resize ");
	return 0;
	*/

	sSessCtrl;
	sLog->Initialize();

	//if (!CUtil::SetRLimit())
	//	return 0;

	if (!g_serverIni.OpenFile("server.ini"))
	{
		IME_ERROR("Cannot open server.ini");
		return 0;
	}

	if (!InitServer())
	{
		IME_ERROR("InitServer failed");
		return 0;
	}
	HookSignals();

	IME_LOG("GameServer Start!");
	
	CTileIsometric CTile;
	TilePos a = {1,0};
	CTile.AddTileByObj(a, 4, 3);

	TilePos b = {0,1};
	if (CTile.IsHaveTileByObj(b, 2, 2))
		IME_LOG("x %u y %u is live", b.x, b.y);

	UnHookSignals();
	EndServer();
	
}
