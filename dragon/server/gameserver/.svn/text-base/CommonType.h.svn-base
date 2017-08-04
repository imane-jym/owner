/*
 * =====================================================================================
 *
 *       Filename:  CommonType.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月27日 05时01分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _COMMONTYPE_H_
#define _COMMONTYPE_H_

#include <stdint.h>
#include <vector>
#include <string>
#include <stdint.h>

#define MAX_BROADCAST_LENGTH 		100        /* 聊天记录单条长度 */
#define MAX_WORLD_CHAT_NUMBER 		20         /* 最大聊天记录数 */
#define MAX_SYS_BROAD_USER_ONE_TIMES 500       /* 每次发送的广播人数上限 */
#define MAX_NOTICE_NUMBER 			 6         /* 最多保存的广播数量 */

enum
{
	WORLD_BROADCAST_TIME = 0,
	TIME_MAX
};

typedef struct RoleBase
{
	uint32_t dwAccountId;
	std::string strAccount;
	std::string strUserName;
	uint16_t wLevel;
	uint32_t dwExp;
	uint32_t dwVipLv;
	uint32_t dwVipTotalExp;
	uint64_t lDollar;
	uint64_t lCoin;
	uint32_t dwEnergy;
	uint32_t dwEnergyTime;
	uint32_t dwVipEndTime;
	uint8_t byStatus;
	uint32_t dwTaskPosition;
	std::string strToken;
	uint32_t dwGameFlow;
} RoleBase;

typedef struct SWorldChat
{
	uint8_t choose;
	uint32_t userid;
	std::string username;
	std::string content;
	uint16_t viplv;
} SWorldChat;

typedef struct SServerData
{
	uint32_t serverid;	
	uint8_t canlogin;
	uint8_t status;
	uint8_t isnew;
	std::string servername;
	std::string ip;
	uint32_t port;
	std::string domain;
	std::string resurl;
}SServerData;

#define PROPERTY_OPT(T,name) \
	T Get##name() { return m_##name;}; \
	void Set##name(T name) \
	{ m_##name = name; \
	}; 

typedef struct HeroProperty
{
	HeroProperty():
	dwSelfAttack(0),dwSelfDefence(0),dwSelfStrength(0),dwSelfHeal(0),dwSelfPowerRecover(0),dwSelfAttackSpeed(0),
	dwSelfAttackTime(0),dwSelfDodge(0),dwSelfCrit(0),dwSelfCritPower(0),dwSelfHit(0),dwSelfSuckBlood(0),
	dwEquipAttack(0),dwEquipDefence(0),dwEquipStrength(0),dwEquipHeal(0),dwEquipPowerRecover(0),dwEquipAttackSpeed(0),
	dwEquipAttackTime(0),dwEquipDodge(0),dwEquipCrit(0),dwEquipCritPower(0),dwEquipHit(0),dwEquipSuckBlood(0), dwCombatValue(0)
	{
	}
	uint32_t dwSelfAttack;
	uint32_t dwSelfDefence;
	uint32_t dwSelfStrength;
	uint32_t dwSelfHeal;
	uint32_t dwSelfPowerRecover;
	uint32_t dwSelfAttackSpeed;
	uint32_t dwSelfAttackTime;
	uint32_t dwSelfDodge;
	uint32_t dwSelfCrit;
	uint32_t dwSelfCritPower;
	uint32_t dwSelfHit;
	uint32_t dwSelfSuckBlood;

	uint32_t dwEquipAttack;
	uint32_t dwEquipDefence;
	uint32_t dwEquipStrength;
	uint32_t dwEquipHeal;
	uint32_t dwEquipPowerRecover;
	uint32_t dwEquipAttackSpeed;
	uint32_t dwEquipAttackTime;
	uint32_t dwEquipDodge;
	uint32_t dwEquipCrit;
	uint32_t dwEquipCritPower;
	uint32_t dwEquipHit;
	uint32_t dwEquipSuckBlood;

	uint32_t dwCombatValue;
} HeroProperty;

#define CALCULATE_HERO_COMBAT_VALUE(t) (t.dwSelfAttack + t.dwSelfDefence + t.dwSelfStrength + t.dwSelfHeal + t.dwSelfPowerRecover + t.dwEquipAttack + t.dwEquipDefence + t.dwEquipStrength + t.dwEquipHeal + t.dwEquipPowerRecover) / 10

#define PACKET_REMAIN_CHECK(p, cmd) \
if (!p.real_empty())\
{\
	IME_ERROR("packet size is unvalid");\
	SendErrorMsg(ERRNO_MSG_PKG_SIZE, cmd);\
	return;\
}\

#define PACKET_REMAIN_CHECK_NO_ROLE(p, cmd, pCRole) \
if (!p.real_empty())\
{\
	IME_ERROR("packet size is unvalid");\
	pCRole->SendErrorMsg(ERRNO_MSG_PKG_SIZE, cmd);\
	return;\
}\

typedef struct DropData
{
	DropData():Dropkey(0), number(0) {}
	uint32_t Dropkey;
	uint32_t number;
	std::vector<uint32_t> count;                /* no_count(不选中的次数) [count ...] */
} DropData;

typedef std::vector<uint32_t> OneProduct;

// probability 都是以10000 做分母
enum
{
	DROP_BY_NUMBER = 1,                         /* type [{seqno dropgroupindex} ...] */
	DROP_BY_SERVER,                             /* type number(允许掉落的次数) dropgroupindex probability*/
	DROP_BY_ROLE,                               /* type number(允许掉落的次数) dropgroupindex probability*/
	DROP_BY_PROBABILITY,                        /* type no_weight(不选中权重) [weigth...] */
	DROP_BY_CHANNEL,                            /* type number(允许掉落的次数) dropgroupindex probability*/
	DROP_BY_DIRECT,                             /* type dropgroupindex probability*/
	DROP_BY_REAL_PROBABILITY,                   /* type no_count(不选中次数) [count ...] */
};

typedef struct TaskData
{
	uint32_t PassTime;
	uint16_t Number;
	uint32_t FlushTime;
} TaskData;

typedef struct NPCData
{
	uint16_t wBatchId;
	uint32_t dwNPCId;
	uint16_t wPos;
	uint16_t wLevel;
	uint32_t dwAttack;
	uint32_t dwDefence;
	uint32_t dwHealth;
	uint32_t dwDropIndex;
	uint32_t dwDropNumber;
	uint32_t dwNormalAttackIndex;
} NPCData;

#define CALCULATE_HERO_ABILITY(grow, lv, init) grow * lv + init

#define ONE_RULE_ARRAY_TO_VECTOR(rule, vec)\
{\
	std::vector<uint32_t> one;\
	for (unsigned int arri = 0; arri < sizeof(rule) / sizeof(rule[0]); arri++)\
	{\
		one.push_back(rule[arri]);\
	}\
	vec.push_back(one);\
}

#define DATA_ARRAY_TO_VECTOR(data, m, n, vec)\
{\
	for(unsigned int arri = 0; arri < sizeof(data) / sizeof(data[0]); arri++)\
	{\
		std::vector<OneProduct> arr;\
		for(unsigned int arrj = 0; arrj < m; arrj++)\
		{\
			OneProduct one;\
			for (unsigned int arrk = 0; arrk < n; arrk++)\
			{\
				one.push_back(data[arri][arrj][arrk]);\
			}\
			arr.push_back(one);\
		}\
		vec.push_back(arr);\
	}\
}

typedef struct CombatResult
{
	uint8_t heropos;
	uint16_t lv;
	uint32_t exp;
	uint32_t explimit;
	uint16_t newlv;
	uint32_t newexp;
	uint32_t newexplimit;
} CombatResult;

#endif
