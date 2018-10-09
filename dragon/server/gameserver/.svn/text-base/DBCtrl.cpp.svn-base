/*
 * DBCtrl.cpp
 *
 *  Created on: 2014-04-21
 *      Author: imane
 */
#include <string>
#include <assert.h>
#include <string.h>
#include "World.h"
#include "DBCtrl.h"
#include "Defines.h"
#include "DatabaseMysql.h"
#include "QueryResult.h"
#include "Field.h"
#include "ShardingDB.h"
#include "WorldDb.h"
#include "Log.h"
#include "EnumDefines.h"
#include "Util.h"
#include "CenterDBCtrl.h"
#include "ConfigData.h"

extern DatabaseMysql LoginDatabase;
extern CShardingDB WorldDb;
extern std::string g_strWorldDatabaseName;
//extern DatabaseMysql CenterDatabase;

extern int g_nVersion;

bool CDBCtrl::ExistsIndex(const char* table, const char* index)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
	QueryResult* result = mysql->PQuery(
			"select * from information_schema.statistics where table_name='%s' and index_name='%s' and table_schema = '%s'",
			table, index, g_strWorldDatabaseName.c_str()
			);

	if ( result )
	{
		delete result;
		return true;
	}
	return false;
}

bool CDBCtrl::ExistsColumn(const char* table, const char* column)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
	QueryResult* result = mysql->PQuery(
			"select * from information_schema.columns where table_name='%s' and column_name='%s' and table_schema='%s'",
			table, column, g_strWorldDatabaseName.c_str()
			);
	if ( result )
	{
		delete result;
		return true;
	}
	return false;
}

bool CDBCtrl::ExistsTable(const char* table)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
	QueryResult* result = mysql->PQuery(
			"select * from information_schema.tables where table_schema='%s' and table_name='%s'",
			g_strWorldDatabaseName.c_str(), table
			);
	if ( result )
	{
		delete result;
		return true;
	}
	return false;
}

bool CDBCtrl::ExistsRecord(const char* table, const char *condition)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
	QueryResult* result = mysql->PQuery(
			"select * from %s where %s",
			table, condition
			);
	if ( result )
	{
		delete result;
		return true;
	}
	return false;
}


//sql 造表
bool CDBCtrl::CreateWorldDB()
{
	std::vector<DatabaseMysql *> vecDBs;
	WorldDb.GetDBConnections(vecDBs);

	for(unsigned int i = 0; i < vecDBs.size(); ++i)
	{
		//暂时只1个库
		//create tables.....
		DatabaseMysql * mysql = vecDBs[i];

//		mysql->PExecute("use card_world;");

		if (!ExistsTable("user_login"))
		{
		////角色行为数据表
		mysql->PExecute(
				"create table user_login( "
				"user_id bigint unsigned primary key,"			//user_id
				"account varchar(64) not null default '',"						//帐号
				"last_login_time int unsigned not null default 0,"				//上次登录时间
				"last_logout_time int unsigned not null default 0,"				//上次下线时间 //挂了就错了～～
				"cur_login_time int unsigned not null default 0,"				//上次登录时间
				"login_day smallint not null default 0,"						//已连续登录几天
				"last_login_ip varchar(32) not null default '',"				//上次登录ip
				"key(account) "

				")engine=innodb DEFAULT charset=utf8;");
		}
		//这里做alter！！！！！！！

		if (!ExistsTable("user_game"))
		{
		////角色游戏数据表
		mysql->PExecute(
				"create table user_game( "
				"user_id bigint unsigned primary key,"					//角色ID
				"account varchar(64) not null ,"						//账号ID
				"name varchar(64) not null default 'unknow',"			//昵称
				"level smallint not null default 0,"					//等级
				"exp int unsigned not null default 0,"					//经验
				"vip_level int not null default 0,"						//vip等级
				"vip_exp int unsigned not null default 0,"				//vip经验
				"dollar bigint unsigned not null default 0,"			//元宝
				"coin bigint unsigned not null default 0,"				//金币
				"energy int unsigned not null default 0,"				//精力
				"energy_time int not null default 0, "					//精力时间
				"vip_end_time int not null default 0, "					//vip截止时间
				"status tinyint unsigned not null default 0,"			//状态
				"task int unsigned not null default 0,"					//任务
				"token varchar(64) not null default 'unknow',"			//昵称
				"game_flow int unsigned not null default 0 "			//玩家游戏流程
				")engine=innodb DEFAULT charset=utf8;");
		}

		////角色游戏数据表blob
		if (!ExistsTable("user_game_blob"))
		{
		mysql->PExecute(
				"create table user_game_blob( "
                                "user_id bigint unsigned primary key,"						//user_id
								"role_other blob not null default '', " 						//角色扩展杂项数据 
								"item blob not null default '', " 						//道具包 
								"hero blob not null default '', " 						//英雄数据
								"equip varchar(255) not null default '', " 						//英雄数据
								"task blob not null default '', " 						//关卡数据
								"building blob not null default '' "                    //城建数据

				")engine=innodb DEFAULT charset=utf8;");
		}

		if (!ExistsTable("global_data"))
		{
			mysql->PExecute(
					"create table global_data( "
					"id bigint unsigned primary key,"						//user_id
					"content BLOB not null default '' "							//礼包数据

					")engine=innodb DEFAULT charset=utf8;");
			mysql->PExecute(
					"insert into global_data(id,content) values(1, '');"
					);
			mysql->PExecute(
					"insert into global_data(id,content) values(2, '');"
					);
			mysql->PExecute(
					"insert into global_data(id,content) values(3, '');"
					);
			mysql->PExecute(
					"insert into global_data(id,content) values(4, '');"
					);
		}
		if (!ExistsTable("user_dollar_record"))
		{
		mysql->PExecute(
				"create table user_dollar_record("
                               "user_id bigint unsigned not null, "						//user_id
                               "order_id int unsigned not null, "						//消费或充值订单号
                               "dollar int not null default 0, "					//消费或充值的钱数量
                               "time int unsigned not null default 0, "				//时间
                               "shop_id int not null default 0, "					//商品ID
                               "number int unsigned not null default 0, "				//购买的数量
                               "type int unsigned not null default 0, "				//类型 0:shop 1:开通工会 2:减CD 3:充值 4:GM 5:各种活动和奖励金钱
                               "step int unsigned not null default 0, "				//购买消费步数 
							   "primary key(user_id, order_id) "

				")engine=innodb DEFAULT charset=utf8;");
		}
	}

	return true;
}

bool CDBCtrl::IsNewRole(uint32_t accountId)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
//	std::string strAccount = strAccountRet;
//	mysql->escape_string(strAccount);
	QueryResult *result = mysql->PQuery(
			"select account "
			"from user_login where user_id = '%u'",
			accountId
			);
	if (result)
	{
		delete result;
		return false;
	}

	return true;
}

//创建玩家基本数据
uint32 CDBCtrl::NewUserData(uint32 accountId, const std::string & strAccountRet)
{
	uint32 dwAccountId = 0;
	DatabaseMysql * mysql = WorldDb.GetDBConnection(dwAccountId);//我们只用一个库
	assert(mysql);

	std::string strAccount = strAccountRet;
	mysql->escape_string(strAccount);

	mysql->PExecute(
			"insert into user_login "
			"(user_id, account) "
			"values (%u, '%s')",
			accountId,
			strAccount.c_str()
			//todo
	);

	dwAccountId = accountId;

	mysql->PExecute(
		"insert into user_game (user_id, name) values(%u, '%u')",
		dwAccountId, dwAccountId
		);
	mysql->PExecute(
		"insert into user_game_blob (user_id) values(%u)",
		dwAccountId
		);
	//todo need log?

	return dwAccountId;
}

bool CDBCtrl::GetAllUserBaseData(std::map<uint32_t, RoleBase> &mapRole)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
	QueryResult *result = mysql->PQueryStrict(
			"select user_id, account, name, level, exp, vip_level, vip_exp, dollar, coin, "
            "energy, energy_time, vip_end_time, status, task, token, game_flow "
			"from user_game"
			);
	if (result)
	{
		int i = 0;
		int number = result->GetRowCount();
		Field *fields = result->Fetch();

		for (int j = 0; j < number; j++)
		{	
			i = 0;
			RoleBase data;
			data.dwAccountId = fields[i++].GetUInt32();
			data.strAccount = fields[i++].GetCppString();
			data.strUserName = fields[i++].GetCppString();
			data.wLevel = fields[i++].GetUInt16();
			data.dwExp = fields[i++].GetUInt32();
			data.dwVipLv = fields[i++].GetUInt32();
			data.dwVipTotalExp = fields[i++].GetUInt32();
			data.lDollar = fields[i++].GetUInt64();
			data.lCoin = fields[i++].GetUInt64();
			data.dwEnergy = fields[i++].GetUInt32();
			data.dwEnergyTime = fields[i++].GetUInt32();
			data.dwVipEndTime = fields[i++].GetUInt32();
			data.byStatus = fields[i++].GetUInt8();
			data.dwTaskPosition = fields[i++].GetUInt32();
			data.strToken = fields[i++].GetCppString();
			data.dwGameFlow= fields[i++].GetUInt32();
			mapRole[data.dwAccountId] = data;

			result->NextRow();
			fields = result->Fetch();
		}
		
		delete result;
		return true;
	}
	return false;
}

void CDBCtrl::UpdateUserBaseData(RoleBase data)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
	mysql->escape_string(data.strAccount);
	mysql->escape_string(data.strUserName);
	mysql->escape_string(data.strToken);
	mysql->PExecute(
			"update user_game set "
			"account = '%s', name = '%s', level = %u, exp = %u, vip_level = %u, vip_exp = %u, dollar = %u, coin = %u, energy = %u, energy_time = %u, vip_end_time = %u, status = %u, task = %u, token = '%s',game_flow = %u "
			"where user_id=%u",
			data.strAccount.c_str(), data.strUserName.c_str(), data.wLevel, data.dwExp, data.dwVipLv, data.dwVipTotalExp, data.lDollar, data.lCoin, data.dwEnergy, data.dwEnergyTime, data.dwVipEndTime, data.byStatus, data.dwTaskPosition, data.strToken.c_str(), data.dwGameFlow, 
			data.dwAccountId
			);
}

bool CDBCtrl::IsHaveRole(uint32 userid)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
	QueryResult *result = mysql->PQuery(
			"select user_id "
			"from user_login where user_id = %u",
			userid
			);
	if (result)
	{
		delete result;
		return false;
	}

	return true;
}

bool CDBCtrl::GetLoginInfo(uint32 dwServerid, const std::string &strIp, int nPort, uint32 dwOnlineNum, uint8_t &can_login, uint8_t &status, uint8_t &is_new, std::string &server_name, std::string &domain, std::string &resurl)
{
	bool ret;
	QueryResult *result = LoginDatabase.PQuery(
			"select can_login, status, is_new, server_name, domain, res_url from gameserver_info where area_id=%d",
			dwServerid
			);
	std::string Ip = strIp;
	LoginDatabase.escape_string(Ip);
	std::string Res = resurl;
	LoginDatabase.escape_string(Res);
	if (result)
	{
		Field *fields = result->Fetch();
		can_login = fields[0].GetUInt8();
		status = fields[1].GetUInt8();
		is_new = fields[2].GetUInt8();
		server_name = fields[3].GetCppString();
		domain = fields[4].GetCppString();
		resurl = fields[5].GetCppString();
		return true;
	}
	else
	{
		ret = LoginDatabase.PExecute(
				"insert into gameserver_info "
				"(area_id, ip, port, online_num, version, update_time, res_url) "
				"values (%d,'%s',%d,%u,%u,%u, '%s')",
				dwServerid,
				strIp.c_str(),nPort,dwOnlineNum,uint32(INNER_VERSION),time(NULL), Res.c_str()
				);
		return ret;
	}
	return false;
}

void CDBCtrl::UpdateLoginInfo(uint32_t serverid, std::string strIp, int nPort, uint32 dwOnlineNum, uint8_t can_login, uint8_t status, uint8_t is_new, std::string servername, std::string domain, std::string resurl)
{
//	QueryResult *result = LoginDatabase.PQuery(
//			"select can_login, status, update_time from gameserver_info where area_id=%d",
//			sWorld->GetServerId()
//			);
	LoginDatabase.escape_string(strIp);
	LoginDatabase.escape_string(servername);
	LoginDatabase.escape_string(domain);
//	if (result)
//	{
//		delete result;
	LoginDatabase.PExecute(
				"update gameserver_info set ip='%s', port = %d, online_num=%u, update_time=%u, version=%u, can_login = %d, status = %d, is_new = %d, server_name = '%s', domain = '%s', res_url = '%s' where area_id=%d",
				strIp.c_str(), nPort, dwOnlineNum, time(NULL), uint32(INNER_VERSION), can_login, status, is_new, servername.c_str(), domain.c_str(), resurl.c_str(), serverid
				);
//	}
//	else
//	{
//		LoginDatabase.PExecute(
//				"insert into gameserver_info "
//				"(area_id, ip, port, online_num, version, update_time) "
//				"values (%d,'%s',%d,%u,%u,%u)",
//				sWorld->GetServerId(),
//				strIp.c_str(),nPort,dwOnlineNum,uint32(INNER_VERSION),time(NULL)
//				);
//		//IME_ERROR("version %u",uint32(SERVER_VERSION));
//	}
}

bool CDBCtrl::IsCanLogin(uint32 serverid)
{
	QueryResult *result = LoginDatabase.PQuery(
			"select can_login,status from gameserver_info where area_id=%d",
			serverid
			);
	if (result)
	{
		Field *fields = result->Fetch();
		bool ret = fields[0].GetBool();
		uint32 status = fields[1].GetUInt32();

		delete result;
		return (ret && status != E_AREA_STATUS_STOP);
	}
	return false;
}



bool CDBCtrl::GetUserLoginData(
		uint32 accountId,
		uint32 &last_login_time,
		uint32 &last_logout_time,
		uint32 &cur_login_time,
		uint32 &login_day,
		std::string &last_login_ip
)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(accountId);
	QueryResult *result = mysql->PQuery(
			"select last_login_time,last_logout_time,cur_login_time,login_day,last_login_ip "
			"from user_login where user_id = %u",
			accountId
			);
	if (result)
	{
		int i = 0;
		Field *fields = result->Fetch();

		last_login_time = fields[i++].GetUInt32();
		last_logout_time = fields[i++].GetUInt32();
		cur_login_time = fields[i++].GetUInt32();
		login_day = fields[i++].GetUInt32();
		last_login_ip = fields[i++].GetCppString();

		delete result;
		return true;
	}
	return false;
}

void CDBCtrl::SaveUserLoginData(
		uint32 accountId,
		uint32 last_login_time,
		uint32 last_logout_time,
		uint32 cur_login_time,
		uint32 login_day,
		std::string last_login_ip
		)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(accountId);
	std::string str = last_login_ip;
	mysql->escape_string(str);
	mysql->PExecute(
			"update user_login set "
			"last_login_time = %u,last_logout_time = %u,cur_login_time = %u,login_day = %u,last_login_ip = '%s' "
			"where user_id=%u",
			last_login_time,last_logout_time,cur_login_time,login_day,str.c_str(),
			accountId
			);

}

void CDBCtrl::SaveGlobalData(const std::string &strtemp, uint32 id)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);

        std::string str = strtemp;
        mysql->escape_string(str);
		mysql->PExecute(
				"update global_data set "
				"content = '%s' "
				"where id = %u",
				str.c_str(),
				id
				);
}

bool CDBCtrl::GetGlobalData(uint32 id, std::string &str)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
	QueryResult *result = mysql->PQuery(
			"select content "
			"from global_data where id = %u", id
			);
	if (result)
	{
		Field *fields = result->Fetch();
		str.assign(fields[0].GetString(), fields[0].GetLength());

		delete result;
		return true;
	}
	return false;
}

bool CDBCtrl::GetUserName(std::set<std::string> &setUserName)
{

	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
	QueryResult *result = mysql->PQuery(
			"select name "
			"from user_game where level != 0"
			);
	if (result)
	{
		int i = 0;
		int j = 0;
		int number = result->GetRowCount();
		Field *fields = result->Fetch();
		setUserName.clear();
		for (; j < number; j++)
		{
			i = 0;
			std::string tmp = fields[i++].GetCppString();
			setUserName.insert(tmp);
			result->NextRow();
			fields = result->Fetch();
		}

		delete result;
		return true;
	}
	return false;
}

bool CDBCtrl::GetUserDataOther(std::string &str, uint32 dwAccountId)           
{                                                                              
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);                        
	QueryResult *result = mysql->PQuery(                                       
			"select role_other "                                               
			"from user_game_blob where user_id = %u", dwAccountId             
			);                                                                 
	if (result)                                                                
	{                                                                          
		Field *fields = result->Fetch();                                       
		str.assign(fields[0].GetString(), fields[0].GetLength());              

		delete result;                                                         
		return true;                                                           
	}                                                                          

	return false;                                                              
}                                                                              

void CDBCtrl::SaveUserDataOther(const std::string &strOther, uint32 dwId)      
{                                                                              
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);                        

	std::string str = strOther;                                            
	mysql->escape_string(str);                                             
	mysql->PExecute(                                                           
			"update user_game_blob set "                                          
			"role_other = '%s' "                                                   
			"where user_id = %u",                                                  
			str.c_str(),                                                           
			dwId                                                                   
			);                                                                     
}                                                                              

bool  CDBCtrl::GetStatus(uint32 accountId, uint32 &status){
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
	QueryResult *result = mysql->PQuery("select status from user_game where user_id = %u",accountId);
	if(result){
		Field *fields = result->Fetch();
		int i = 0;
		uint32 limit = fields[i++].GetUInt32();
		status = limit;
		return true;
	}
	return false;
}

void  CDBCtrl::SetStatus(uint32 accountId, uint32 status){
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
	mysql->PExecute("update user_game set status = %u where user_id = %u",status,accountId);
}


void CDBCtrl::GetBuildingData(uint32 userId, std::string &data) {
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
	QueryResult *result = mysql->PQuery("select building from user_game_blob where  user_id = %u",userId);
	if(result){
		Field *fields = result->Fetch();
		data.assign(fields[0].GetString(), fields[0].GetLength());
	}
}

void CDBCtrl::SaveBuildingData(uint32 userId, std::string data) {
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
	mysql->escape_string(data);
	mysql->PExecute("update user_game_blob set building = '%s' where userId = %u",data.c_str(),userId);
}


bool CDBCtrl::GetUserItemPacketData(std::string &item, const uint32 &dwAccountId)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(dwAccountId);
	QueryResult *result = mysql->PQuery(
			"select item "
			"from user_game_blob where user_id = %u",
			dwAccountId
			);
	if (result)
	{
		int i = 0;
		Field *fields = result->Fetch();
		item.assign(fields[i].GetString(), fields[i].GetLength());
		delete result;
		return true;
	}
	return false;
}

void CDBCtrl::SaveUserItemPacketData(const std::string &item, const uint32 &dwAccountId)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(dwAccountId);

	std::string stritem = item;
	mysql->escape_string(stritem);
	mysql->PExecute(
			"update user_game_blob set "
			"item = '%s' "
			"where user_id=%u",
			stritem.c_str(),
			dwAccountId
			);
}

void CDBCtrl::LogShopRecord(const uint32 &dwAccountId, uint32 order, uint32 dollar, uint32 shopid, uint32 number, uint32 type)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(dwAccountId);
	if (mysql->PExecute(
			"insert into user_dollar_record "
			"(user_id, order_id, dollar, time, shop_id, number, type, step) "
			"values (%u, %u, %u, %u, %u, %u, %u, 0) ",
			dwAccountId, order, dollar, time(NULL), shopid, number, type
			//todo
	))
	{
		if (type != E_DC_CHARGE && type != E_DC_GM_GIVE && type != E_DC_GM_DEL && type != E_DC_GIVE)
		{
			if (CenterDBCtrl::InsertPurchaseInfo(dwAccountId, type * 1000000 + shopid, number, dollar, (uint32_t)time(NULL)))
			{
				IME_CHAR_LOG(0, "ORDER_DOLLAR_CENTER", "content=insert purchase_info fail|user_id=%u|order_id=%u|dollar=%u|time=%u|shop_id=%u|number=%u|type=%u", dwAccountId, order, dollar, (uint32_t)time(NULL), shopid, number, type);
			}
		}
		return;
	}
	else
	{
		IME_CHAR_LOG(0, "ORDER_DOLLAR_WORLD", "content=Description: insert shop record fail|user_id=%u|order_id=%u|dollar=%u|time=%u|shopid=%u|number=%u|type=%u", dwAccountId, order, dollar, (uint32_t)time(NULL), shopid, number, type);
	}
}

bool CDBCtrl::GetShopOrderId(uint32 userid, uint32 &order_id)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(0);//我们只用一个库

	QueryResult* retChar = mysql->PQuery(
		"select max(order_id) from user_dollar_record where user_id = '%u'",
		userid
		);
	if (!retChar)
	{
		return false;
	}
	Field *fieldsChar = retChar->Fetch();
	uint32 dwUserId = fieldsChar[0].GetUInt32();
	delete retChar;

	order_id = dwUserId + 1;
	return true;
}

void CDBCtrl::LogShopStep(const uint32 &dwAccountId, uint32 order, uint8_t step)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(dwAccountId);

	if (mysql->PExecute(
			"update user_dollar_record set "
			"step = %u "
			"where user_id= %u and order_id = %u",
			step,
			dwAccountId, order
			))
	{
		return;
	}
	else
	{
		IME_CHAR_LOG(0, "ORDER_DOLLAR_WORLD", "content=Description: update shop record fail. second step add product|user_id=%u|order_id=%u|step=%u", dwAccountId, order, step);
	}
}

bool CDBCtrl::GetUserHeroData(std::string &item, const uint32 &dwAccountId)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(dwAccountId);
	QueryResult *result = mysql->PQuery(
			"select hero "
			"from user_game_blob where user_id = %u",
			dwAccountId
			);
	if (result)
	{
		int i = 0;
		Field *fields = result->Fetch();
		item.assign(fields[i].GetString(), fields[i].GetLength());
		delete result;
		return true;
	}
	return false;
}

void CDBCtrl::SaveUserHeroData(const std::string &item, const uint32 &dwAccountId)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(dwAccountId);

	std::string stritem = item;
	mysql->escape_string(stritem);
	mysql->PExecute(
			"update user_game_blob set "
			"hero = '%s' "
			"where user_id=%u",
			stritem.c_str(),
			dwAccountId
			);
}

bool CDBCtrl::GetUserEquipData(std::string &item, const uint32 &dwAccountId)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(dwAccountId);
	QueryResult *result = mysql->PQuery(
			"select equip "
			"from user_game_blob where user_id = %u",
			dwAccountId
			);
	if (result)
	{
		int i = 0;
		Field *fields = result->Fetch();
		item.assign(fields[i].GetString(), fields[i].GetLength());
		delete result;
		return true;
	}
	return false;
}

void CDBCtrl::SaveUserEquipData(const std::string &item, const uint32 &dwAccountId)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(dwAccountId);

	std::string stritem = item;
	mysql->escape_string(stritem);
	mysql->PExecute(
			"update user_game_blob set "
			"equip = '%s' "
			"where user_id=%u",
			stritem.c_str(),
			dwAccountId
			);
}

bool CDBCtrl::GetUserOneBlobData(std::string &data, const uint32 &dwAccountId, const char *strTable, const char *strfield)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(dwAccountId);
	QueryResult *result = mysql->PQuery(
			"select %s "
			"from %s where user_id = %u",
			strfield, strTable, dwAccountId
			);
	if (result)
	{
		int i = 0;
		Field *fields = result->Fetch();
		data.assign(fields[i].GetString(), fields[i].GetLength());
		delete result;
		return true;
	}
	return false;
}

void CDBCtrl::SaveUserOneBlobData(const std::string &item, const uint32 &dwAccountId, const char *strTable, const char *strfield)
{
	DatabaseMysql * mysql = WorldDb.GetDBConnection(dwAccountId);

	std::string stritem = item;
	mysql->escape_string(stritem);
	mysql->PExecute(
			"update %s set "
			"%s = '%s' "
			"where user_id=%u",
			strTable, strfield,
			stritem.c_str(),
			dwAccountId
			);
}

