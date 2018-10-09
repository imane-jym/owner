/*
 * DBCtrl.h
 *
 *  Created on: 2011-6-21
 *      Author: yq
 */

#ifndef _DB_CTRL_H
#define _DB_CTRL_H
#include "Defines.h"
#include <string>
#include <map>
#include <vector>
#include <set>
#include "CommonType.h"
#include "RoleBase.h"

class CDBCtrl
{
public:
	//sql 造表
	static bool CreateWorldDB();

	static bool IsNewRole(uint32_t AccountId);

	//创建玩家基本数据
	static uint32 NewUserData(uint32 accountId, const std::string & strAccountRet);

	static bool GetAllUserBaseData(std::map<uint32_t, RoleBase> &vecRole);
	static void UpdateUserBaseData(RoleBase data);

	static bool IsHaveRole(uint32 userid);

	static bool GetLoginInfo(uint32 dwServerid, const std::string &m_strIp, int m_nPort, uint32 onlinenum, uint8_t &can_login, uint8_t &status, uint8_t &is_new, std::string &server_name, std::string &domain, std::string &resurl);
	static void UpdateLoginInfo(uint32 serverid, std::string strIp, int nPort, uint32 dwOnlineNum, uint8_t can_login, uint8_t status, uint8_t is_new, std::string servername, std::string domain, std::string resurl);
	static bool IsCanLogin(uint32 serverid);

	static bool GetUserLoginData(
			uint32 accountId,
			uint32 &last_login_time,
			uint32 &last_logout_time,
			uint32 &cur_login_time,
			uint32 &login_day,
			std::string &last_login_ip
			);
	static void SaveUserLoginData(
			uint32 accountId,
			uint32 last_login_time,
			uint32 last_logout_time,
			uint32 cur_login_time,
			uint32 login_day,
			std::string last_login_ip
			);
	static void SaveGlobalData(const std::string &strtemp, uint32 id);
	static bool GetGlobalData(uint32 id, std::string &str);
	static bool GetUserName(std::set<std::string> &setUserName);

	static bool GetUserDataOther(std::string &str, uint32 dwAccountId);
	static void SaveUserDataOther(const std::string &strOther, uint32 dwId);
	static bool GetStatus(uint32 accountId, uint32 &status);
	static void SetStatus(uint32 accountId, uint32 status);

	static void GetBuildingData(uint32 userId, std::string &data);
	static void SaveBuildingData(uint32 userId, std::string data);
	static bool GetUserItemPacketData(std::string &item, const uint32 &dwAccountId);
	static void SaveUserItemPacketData(const std::string &item, const uint32 &dwAccountId);
	static void LogShopRecord(const uint32 &dwAccountId, uint32 order, uint32 dollar, uint32 shopid, uint32 number, uint32 type);
	static bool GetShopOrderId(uint32 userid, uint32 &order_id);
	static void LogShopStep(const uint32 &dwAccountId, uint32 order, uint8_t step);

	static bool GetUserHeroData(std::string &item, const uint32 &dwAccountId);
	static void SaveUserHeroData(const std::string &item, const uint32 &dwAccountId);

	static bool GetUserEquipData(std::string &item, const uint32 &dwAccountId);
	static void SaveUserEquipData(const std::string &item, const uint32 &dwAccountId);

	static bool GetUserOneBlobData(std::string &item, const uint32 &dwAccountId, const char *strTable, const char *strfield);
	static void SaveUserOneBlobData(const std::string &item, const uint32 &dwAccountId, const char *strTable, const char *strfield);

	static bool GetUserTaskData(std::string &item, const uint32 &dwAccountId)
	{
		return GetUserOneBlobData(item, dwAccountId, "user_game_blob", "task");
	}

	static void SaveUserTaskData(const std::string &item, const uint32 &dwAccountId)
	{
		return SaveUserOneBlobData(item, dwAccountId, "user_game_blob", "task");
	}
private:
	static bool ExistsIndex( const char* table, const char* index );
	static bool ExistsColumn( const char* table, const char* column );
	static bool ExistsTable( const char* table );
	static bool ExistsRecord(const char* table, const char *condition);

	CDBCtrl();
	~CDBCtrl();
};
#endif
