/*
 * ConfigData.h
 *
 *  Created on: 2011-7-5
 *      Author: yq
 */

#ifndef CONFIGDATA_H_
#define CONFIGDATA_H_

#include "Defines.h"
#include "CommonConfig.h"
#include "EnumDefines.h"
#include <map>
#include <vector>
#include <string>
#include <stdint.h>

#define TECH_TYPE_MAX 2

//////////////////////////////////
typedef bool (*FuncInit)(const std::string &strFilePath);
typedef bool (*FuncValid)(const std::string &strFilePath);
bool ConfInit(std::string strpath);
bool ConfReload(std::string strpath, std::string strTable);
bool ConfValid(std::string strpath, std::string strTable);

typedef struct _STC_CONF_TEST
{
	uint16 wTestId;

}STC_CONF_TEST;

class CConfTest
{
public:
	typedef std::map<uint16, STC_CONF_TEST> MapData;

public:
	static bool Init(const std::string& strFilePath);
	static bool ReadConfig(const std::string& strFilePath, MapData &map);
	static bool Valid(const std::string& strFilePath); 

	static STC_CONF_TEST* Find(uint16 wTestId);

private:
	static MapData m_mapData;
};

struct STC_CONF_ROLE {
	uint32 dwIndex;
	uint32 dwExpInterval;
	uint32 dwExpLimit;
	uint32 dwEnergyLimit;
	uint32 dwFriendLimit;
};			

typedef struct STC_CONF_ROLE STC_CONF_ROLE;

class CConfRole
{
public:
    typedef std::map<uint32, STC_CONF_ROLE> MapData;
    static bool Init(const std::string& strFilePath);
	static bool ReadConfig(const std::string& strFilePath, MapData &map, std::vector<uint32_t> &vec);
	static bool Valid(const std::string& strFilePath);
    static STC_CONF_ROLE* Find(uint32 dwIndex);
	static uint32 FindLevel(uint32 dwExp);
	static uint32 GetMaxExp();
	static uint32 GetMaxExpIntervalLv(uint32_t lv);
	static uint32 GetMaxLevel();
	static void GetResult(uint32_t lv, uint32_t exp, uint32_t &newlv, uint32_t &newexp);

private:
    static MapData m_mapData;
	static std::vector<uint32> m_vecExpToLevel;
};

struct STC_CONF_HERO_EXP {
	uint32 dwIndex;
	uint32 dwExpInterval;
	uint32 dwExpLimit;
};			

typedef struct STC_CONF_HERO_EXP STC_CONF_HERO_EXP;

class CConfHeroExp
{
public:
    typedef std::map<uint32, STC_CONF_HERO_EXP> MapData;
    static bool Init(const std::string& strFilePath);
	static bool ReadConfig(const std::string& strFilePath, MapData &map, std::vector<uint32_t> &vec);
	static bool Valid(const std::string& strFilePath);
    static STC_CONF_HERO_EXP* Find(uint32 dwIndex);
//	static uint32 FindLevel(uint32 dwExp);
	static uint32 GetMaxExp(float grow);
	static uint32 GetMaxExpIntervalLv(uint32_t lv, float grow);
	static uint32 GetMaxLevel();
	static void GetResult(uint32_t lv, uint32_t exp, uint32_t &newlv, uint32_t &newexp, float grow);

private:
    static MapData m_mapData;
	static std::vector<uint32> m_vecExpToLevel;
};
#endif /* CONFIGDATA_H_ */
