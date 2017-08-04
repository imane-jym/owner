﻿/*
 * =====================================================================================
 *
 *       Filename:  CommonConfig.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月24日 05时11分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _COMMONCONFIG_H_
#define	_COMMONCONFIG_H_ 

#include "Defines.h"
#include <map>
#include <vector>
#include <string>
#include <stdint.h>

#define MAX_UPGRADE_COMBINE_NUMBER 4
typedef struct _STC_CONF_ITEM
{
	uint32 dwIndex;
	uint16 wType;
	uint16 wDisplayType;
	std::string strTitle;
	std::string strContent;
	uint16 wStar;
	uint32 dwUseLevel;
	uint16 wProfession;
	uint32 dwInitAttack;
	uint32 dwAttackGrow;
	uint32 dwInitDefence;
	uint32 dwDefenceGrow;
	uint32 dwInitStrength;
	uint32 dwStrengthGrow;
	uint32 dwInitHeal;
	uint32 dwHealGrow;
	uint32 dwInitPowerRecover;
	uint32 dwPowerRecoverGrow;
	uint32 dwAttackSpeed;
	uint32 dwAttackTime;
	uint32 dwDodge;
	uint32 dwCritPro;
	uint32 dwCritPower;
	uint32 dwHit;
	uint32 dwSuckBlood;
	uint32 dwHarm;
	uint32 dwDefaultSkillCol[2];
	uint32 dwRandSkillCol[2];
	uint32 dwSuitSkill;
//	uint32 dwCombineItem[MAX_UPGRADE_COMBINE_NUMBER];
//	uint32 dwNumber[MAX_UPGRADE_COMBINE_NUMBER];
//	uint32 dwCombineTime;
//	uint32 dwCombineConsumeCoin;
	uint32 dwDropMission[3];
	std::string strPicPath;
}STC_CONF_ITEM;

class CConfItem
{
public:
	typedef std::map<uint32, STC_CONF_ITEM> MapData;

public:
	static bool Init(const std::string& strFilePath);
	static bool ReadConfig(const std::string& strFilePath, MapData &map);
	static bool Valid(const std::string& strFilePath); 

	static STC_CONF_ITEM* Find(uint32 wTestId);

private:
	static MapData m_mapData;
};

typedef struct _STC_CONF_VIP
{
	uint32 dwIndex;
	uint32 dwExpInterval;
	uint32 dwExpLimit;
}STC_CONF_VIP;

class CConfVip
{
public:
	typedef std::map<uint32, STC_CONF_VIP> MapData;

public:
	static bool Init(const std::string& strFilePath);
	static bool ReadConfig(const std::string& strFilePath, MapData &map, std::vector<uint32_t> &vec);
	static bool Valid(const std::string& strFilePath); 

	static STC_CONF_VIP* Find(uint32 wTestId);
	static uint32 FindLevel(uint32 dwExp);
	static uint32 GetMaxExp();
	static uint32 GetMaxExpIntervalLv(uint32_t lv);
	static uint32 GetMaxLevel();
	static void GetResult(uint32_t lv, uint32_t exp, uint32_t &newlv, uint32_t &newexp);

private:
	static MapData m_mapData;
	static std::vector<uint32> m_vecExpToLevel;
};

typedef struct _STC_CONF_HERO
{
	uint32 dwId;
	std::string strName;
	std::string strDesc;
	uint32 dwPos;
	uint32 dwJob;
	uint32 dwExp;
	uint32 dwLevelLimit;
	uint32 dwAttack;
	uint32 dwAttackGrow;
	uint32 dwDefence;
	uint32 dwDefenceGrow;
	uint32 dwStrong;
	uint32 dwStrongGrow;
	uint32 dwLifereconver;
	uint32 dwLifereconverGrow;
	uint32 dwRecover;
	uint32 dwRecoverGrow;
	uint32 dwAttackSpeed;
	uint32 dwAttackInterval;
	uint32 dwDodge;
	uint32 dwCrit;
	uint32 dwCritValue;
	uint32 dwHitratio;
	uint32 dwSuckblood;
	uint32 dwSkillId[4];
	uint32 dwAvatarId;
}STC_CONF_HERO;

class CConfHero
{
public:
	static bool Init( const std::string &path );
	static const STC_CONF_HERO* Find( uint32 Id );
	static uint32 Count() { return datas.size(); }

	typedef std::map<uint32, STC_CONF_HERO> MapData;
	typedef std::vector<STC_CONF_HERO*> VecData;
	static uint32 VecSize() { return vecDatas.size(); }
	static const STC_CONF_HERO* At( uint32 idx ); 
private:
	static MapData datas;
	static VecData vecDatas;
};

typedef struct _STC_CONF_SKILL
{
	uint32 dwId;
	std::string strName;
	std::string strDesc;
	uint32 dwAttribute;
	uint32 dwJob;
	uint32 dwLimitLevel;
	uint32 dwUseType; // 1 MT 2 AT
	uint32 dwType;
	uint32 dwDamage;
	uint32 dwTargetRule;
	uint32 dwAttackRange[2];
	uint32 dwSettlementRule;
	uint32 dwImpactCount;
	uint32 dwAttackDistance;
	std::string strSingMotion;
	std::string strSingEffect;
	uint32 dwPerBreak;
	std::string strMotion;
	uint32 dwPostBreak;
	uint32 dwAttackEffect;
	uint32 dwBeatEffect;
	uint32 dwCD;
	uint32 dwRageCost;
	uint32 dwSuckBlood;
	uint32 dwTargetOffsetX;
	uint32 dwTargetOffsetY;
	uint32 dwHitPer;
	uint32 dwTargetBuff;
	uint32 dwSpecialBuff;
	std::string strIcon;
	uint32 dwAddPerLevelDamage;
	uint32 dwAddPerLevelCure;
	uint32 dwAddPerLevelHitPer;
	uint32 dwAddPerLevelBuffHitPer;
}STC_CONF_SKILL;

class CConfSkill
{
public:
	static bool Init( const char *path );
	static const STC_CONF_SKILL *Find( uint32 Id );
	typedef std::map<uint32_t, STC_CONF_SKILL> MapData;
private:
	static MapData datas;
};

typedef struct _STC_CONF_UPGRADE
{
	uint32 dwCombineId;
	uint16 wLevel;
	uint32 dwIndex;
	uint32 dwCombineItem[MAX_UPGRADE_COMBINE_NUMBER];
	uint32 dwNumber[MAX_UPGRADE_COMBINE_NUMBER];
	uint32 dwCombineTime;
	uint32 dwCombineConsumeCoin;
}STC_CONF_UPGRADE;

class CConfUpgrade
{
public:
	typedef std::map<uint32, STC_CONF_UPGRADE> MapData;

public:
	static bool Init(const std::string& strFilePath);
	static bool ReadConfig(const std::string& strFilePath, MapData &map);
	static bool Valid(const std::string& strFilePath); 

	static const STC_CONF_UPGRADE* Find(uint32 dwCombineId);

private:
	static MapData m_mapData;
};

#define MAX_AREA_FIRST_DROP 2
#define MAX_AREA_NPC 10
typedef struct _STC_CONF_AREA
{
	uint32 dwIndex;
	uint16 wArea;
	uint16 wDiffculty;
	std::string strName;
	std::string strContent;
	uint16 wType;
	uint32 wLevelLimit;
	uint32 dwNeedTaskIndex;
	uint32 dwCD;
	uint16 wEnergyConsume;
	uint32 dwChallengeNumber;
	uint32 dwRoleExp;
	uint32 dwHeroExp;
	uint32 dwCoin;
	uint32 dwFirstDropIndex[MAX_AREA_FIRST_DROP];
	uint32 dwFirstNumber[MAX_AREA_FIRST_DROP];
	std::string strBackGroud;
	std::string strStory;
	uint32 dwNextIndex;
	uint32 dwNPCId[MAX_AREA_NPC];
}STC_CONF_AREA;

class CConfArea
{
public:
	typedef std::map<uint32, STC_CONF_AREA> MapData;

public:
	static bool Init(const std::string& strFilePath);
	static bool ReadConfig(const std::string& strFilePath, MapData &map);
	static bool Valid(const std::string& strFilePath); 

	static const STC_CONF_AREA* Find(uint32 dwCombineId);

	static std::vector<const STC_CONF_AREA*> FindbyAreaId( uint32 dwAreaId );

private:
	static MapData m_mapData;
};

#define MAX_NPC_MONSTER 6
typedef struct _STC_CONF_NPC
{
	uint32 dwIndex;
	uint16 wLevel;
	uint32 dwNPCId[MAX_NPC_MONSTER];
	uint16 wPos[MAX_NPC_MONSTER];
	uint32 dwAttack[MAX_NPC_MONSTER];
	uint32 dwDefence[MAX_NPC_MONSTER];
	uint32 dwHealth[MAX_NPC_MONSTER];
	uint32 dwPro[MAX_NPC_MONSTER];
	uint32 dwDropIndex[MAX_NPC_MONSTER];
	uint32 dwDropNumber[MAX_NPC_MONSTER];
}STC_CONF_NPC;

class CConfNPC
{
public:
	typedef std::map<uint32, STC_CONF_NPC> MapData;

public:
	static bool Init(const std::string& strFilePath);
	static bool ReadConfig(const std::string& strFilePath, MapData &map);
	static bool Valid(const std::string& strFilePath); 

	static const STC_CONF_NPC* Find(uint32 dwCombineId);

private:
	static MapData m_mapData;
};
#endif
