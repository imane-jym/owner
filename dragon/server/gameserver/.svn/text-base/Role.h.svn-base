#ifndef _ROLE_H_
#define _ROLE_H_

#include "Handler.h"
#include "Defines.h"
#include "DBCtrl.h"
#include "DynamicStruct.h"
#include "Log.h"
#include "RoleBase.h"
#include "Util.h"
#include "GlobalConfig.h"
#include "Shop.h"
#include "CommonType.h"
#include "EnumDefines.h"
#include <time.h>
#include <stdint.h>
#include <algorithm>
#include "Hero.h"

#define PROPERTY_DEF(T,name) \
	T Get##name() { return m_##name;}; \
	void Set##name(T name, bool bSend = false) \
	{ m_##name = name; \
	setProperty(E_ROLE_##name, name); \
	if (bSend) SendProUpdate(); \
	;}; \

#define PROPERTY_DEF_NOUPDATE(T,name) \
	T Get##name() { return m_##name;}; \
	void Set##name(T name) \
	{ m_##name = name; \
	}; \

//class CLuaScript;
class CAnnouncement;
class CItem;
class CHero;
class CTask;

class CRole : public CRoleBase  //tolua_export
{//tolua_export
public:


public:

	enum
	{
		E_SQL_RESULT_SUCC,				//成功
		E_SQL_RESULT_SQL_ERROR,			//sql语句错误
		E_SQL_RESULT_NO_ROLE,			//新角色
	};

	CRole(CHandlerPlayersession* pSess);
	virtual ~CRole();
	void SetSess(CHandlerPlayersession* pSess) { m_pSession = pSess; }

	bool Init(uint32 dwAccountId, const std::string & strAccount);
	void SendLoginData();
	int LoadRole(uint32_t accountId);

	void SetInitError() {m_bIsInitOK = false;};

	void SaveAllData();

	void Online();
	void Offline();
	void SendPacket(WorldPacket * packet);
	void SendErrorMsg(uint16 wErrorMsgNum, uint16 wCmd = 0);
	void SendErrorStr(const std::string& strMsg);
	void SendMsgStr(const std::string& strMsg);

	void SendProUpdate();
	CHandlerPlayersession* GetSession() {return m_pSession;}

	//////////////////////////// 基本数值计算 //////////////////////////////////////////////
	
	int Calculate(bool IsUpdate = false);

	///////////////////////////////////////////////
	void OnTimer5s();
	void OnTimer1s();
	void OnTimer3min();

	void TestScriptByName(const std::string & strName);

	////////////////////////////////////////////////////

	//玩家基本信息
	void SendPlayerBaseInfo();
//	void PackForTeam(WorldPacket &info);

	void OnGMCmd(std::string & strContent);

	bool IsGM() { return IS_GM(GetbyStatus());};

	uint32_t GetNewObjId() {return ++m_dwInitNumber;};
	uint32_t GetCurrentMaxObjId() {return m_dwInitNumber;};
	uint32_t GetdwInitNumber() {return m_dwInitNumber;};

	void SendEnergyNotEnough(uint16 wCmd);
	bool IsInitRoleInfo();
	void HandlerInitRole(WorldPacket &pkg);

	void HandlerWorldBroadCastInfo();
	void HandlerWorldBroadCast(WorldPacket &pkg);

	void PkgWorldBroadCastInfo(uint8_t choose, std::string content, WorldPacket &info);
	void statisticsRole();

	uint16 GetChannel() { return m_pSession->GetwChannel(); }

	int OtherDataGet();
	void OtherDataSave();

	CItem *GetclsItemPacket() {return m_clsItemPacket;};
	CTask *GetclsTask() {return m_clsTask;};

	uint64_t GetNewCirculateId() {return ++m_lCirculateId;};
	uint64_t GetCurrentCirculateId() {return m_lCirculateId;};

	uint32_t GetNewOrderId() {return ++m_dwOrderId;};
	uint32_t GetCurrentOrderId() {return m_dwOrderId;};

	void SendObjEffect(std::vector< std::vector<uint32_t> > tmp);
	void SendEffectCombatResult(uint8_t combat_result, const std::vector<CombatResult> hero, uint32_t coin, uint32_t roleexp, uint32_t heroexp, uint32_t lv, uint16_t exp, uint32_t newlv, uint16_t newexp);
	uint8_t GetbyNoSendLoginData() { return m_byNoSendLoginData; };
	void SetbyNoSendLoginData(uint8_t login) {m_byNoSendLoginData = login; };

	void HandlerEquipOpt(WorldPacket &pkg);
	int LoadEquip();
	void SaveEquip();
	void HandlerEquipInfo(int pos = -1);
	int LoadHero();
	void SaveHero();
	void HandlerHeroChange(WorldPacket &pkg);
	void HandlerHeroInfo(int pos = -1);

	void HandlerItemCombine(WorldPacket &pkg);
	const std::vector< CHero *>& GetvecHero() { return m_vecHero; }

	int HeroCome(int pos);

private:

	CHandlerPlayersession * m_pSession;

	uint32_t m_dwInitNumber;
	bool m_bIsInitOK;
	uint32_t m_dwUserOnlineTime;
	uint8_t m_byFirstLogin;
	uint32_t m_loginauto;
	uint32_t m_dwGmFlushTime;

	uint32_t m_wOtherDataversion;
	std::vector<uint32_t> m_vecTime;

	CItem *m_clsItemPacket;
	CTask *m_clsTask;

	uint64_t m_lCirculateId; 
	uint32_t m_dwOrderId;
	uint8_t m_byNoSendLoginData;

	std::vector< CHero* > m_vecHero;               /* hero */
	std::vector< std::vector<uint32_t> > m_vecEquip; /* equipment */
	std::vector< HeroProperty > m_vecHeroProperty; /* total detail property */
	std::set< uint32_t > m_setEquipFilter;      /* used to filter duplicate equip */

	uint32_t m_dwTotalCombatValue;
};//tolua_export

int GiveGameProduct(CRole *pCRole, std::vector<uint32_t> in, std::vector<uint32_t> &out, int source, uint64_t cir);
int IsObjValid(std::vector< std::vector<uint32_t> > vproduct);

int IsObjValidDropGroup(const std::vector< std::vector<uint32_t> > &vecRule, const std::vector< std::vector<OneProduct> > &vecDropData, const DropData &common);
std::vector<OneProduct> GetDropGroupId(const std::vector< std::vector<uint32_t> > &vecRule, const std::vector< std::vector<OneProduct> > &vecDropData, DropData &common);  

#endif
