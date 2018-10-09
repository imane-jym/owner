#include "GlobalConfig.h"
#include "miniini/miniini.h"
#include "Log.h"
#include "EnumDefines.h"

#include <stdlib.h>

#include "ConfigData.h"
#include "WorldPacket.h"
#include "Role.h"
#include "CmdDefine.h"

//所有全局参数 如果读取不到 则采用默认值

#define READ_INT_FUN(strRead, nValue) \
do { \
	if (!pConfRole->ReadInt(strRead, nValue)) \
	{ \
		IME_ERROR("GLOBAL INI ERROR [%s]", strRead); \
		return false; \
	} \
} while(0)

#define READ_INTS_FUN(strRead, vecValue) \
do { \
	std::string strTmp = strRead; \
	vecValue.clear(); \
	if (!pConfRole->ReadInts(strTmp, vecValue)) \
	{ \
	IME_ERROR("GLOBAL INI ERROR [%s]", strRead); \
	return false; \
	} \
} while(0)

#define READ_STR_FUN(strRead, strValue) \
do { \
	if (!pConfRole->ReadString(strRead, strValue)) \
	{ \
		IME_ERROR("GLOBAL INI ERROR [%s]", strRead); \
		return false; \
	} \
} while(0)

#define READ_BOOL_FUN(strRead, bValue) \
	do { \
	if (!pConfRole->ReadBool(strRead, bValue)) \
	{ \
		IME_ERROR("GLOBAL INI ERROR [%s]", strRead); \
		return false; \
	} \
} while(0)

#define READ_FLOAT_FUN(strRead, fValue) \
	do { \
	if (!pConfRole->ReadFloat(strRead, fValue)) \
	{ \
		IME_ERROR("GLOBAL INI ERROR [%s]", strRead); \
		return false; \
	} \
} while(0)

#define READ_STR_FUN_SAFE(strRead, strValue, strDefault) \
do { \
	if (!pConfRole->ReadString(strRead, strValue)) \
	{ \
		IME_ERROR("Missing "strRead" info, use default: %u", strValue);\
		strValue = strDefault; \
	} \
} while(0)

#define READ_INT_FUN_OTHER(strRead, strValue) \
	if (!configOther->ReadInt(strRead, strValue)) \
	{ \
		IME_ERROR("Missing "strRead" info, use default: %u", strValue);\
		return false;\
	}\

#define READ_INTS_FUN_OTHER(strRead, strValue) \
	strValue.clear();\
	if (!configOther->ReadInts(strRead, strValue)) \
	{ \
		IME_ERROR("Missing "strRead" info");\
		return false;\
	}\

#define READ_STR_FUN_OTHER(strRead, strValue) \
	if (!configOther->ReadString(strRead, strValue)) \
	{ \
		IME_ERROR("Missing "strRead" info, use default: %s", strValue.c_str()); \
		return false;\
	} \

#define READ_STRS_FUN_OTHER(strRead, strValue) \
	strValue.clear();\
	if (!configOther->ReadStrings(strRead, strValue)) \
	{ \
		IME_ERROR("Missing "strRead" info"); \
		return false;\
	} \


std::string GlobalConfig::strTestName;
float GlobalConfig::fTestFloat = 0.0f;
int GlobalConfig::nTestInt = 255;
bool GlobalConfig::bTestBool = false;

int GlobalConfig::EnergyRate = 600;
int GlobalConfig::InitCoin = 100;
int GlobalConfig::InitDollar = 100;
int GlobalConfig::WorldBroadCD = 300;
std::string GlobalConfig::NoticeTypeName = "系统";
int GlobalConfig::FreeMaxVipLevel = 4;

//int GlobalConfig::InitHeroAvatarHair = 0;
//int GlobalConfig::InitHeroAvatarEye = 0;
//int GlobalConfig::InitHeroAvatarNose = 0;
//int GlobalConfig::InitHeroAvatarMouth = 0;

void GlobalConfig::SendData(CRole *pCRole)
{
	WorldPacket info(CMD_SC_GLOBAL_INFO);
	pCRole->SendPacket(&info);
}

bool GlobalConfig::Init(std::string strPath)
{
	INIFile configIni;
	if (!configIni.OpenFile(strPath.c_str()))
	{
		IME_ERROR("Cannot open %s",strPath.c_str());
		return false;
	}

	//section test
	INISection * configTest = configIni.GetSection("test");
	if (!configTest)
	{
		IME_ERROR("Miss section [test] in %s",strPath.c_str());
		return false;
	}

	if (!configTest->ReadString("test_name",strTestName))
	{
		IME_ERROR("Missing test_name info, use default: %s",strTestName.c_str());
	}

	if (!configTest->ReadFloat("test_float",fTestFloat))
	{
		IME_ERROR("Missing test_float info, use default: %f",fTestFloat);
	}

	if (!configTest->ReadInt("test_int",nTestInt))
	{
		IME_ERROR("Missing test_int info, use default: %d",nTestInt);
	}

	if (!configTest->ReadBool("test_bool",bTestBool))
	{
		IME_ERROR("Missing test_bool info, use default: %d",bTestBool);
	}
	
	INISection *configOther = configIni.GetSection("other");
	if (!configOther)
	{
		IME_ERROR("Miss section [other] in %s",strPath.c_str());
	}

	READ_INT_FUN_OTHER("EnergyRate", EnergyRate);
	READ_INT_FUN_OTHER("InitCoin", InitCoin);
	READ_INT_FUN_OTHER("InitDollar", InitDollar);
	READ_INT_FUN_OTHER("WorldBroadCastCD", WorldBroadCD);
	READ_STR_FUN_OTHER("NoticeTypeName", NoticeTypeName);
	READ_INT_FUN_OTHER("FreeMaxVipLevel", FreeMaxVipLevel);
//	READ_INT_FUN_OTHER("InitHeroAvatarHair", InitHeroAvatarHair);
//	READ_INT_FUN_OTHER("InitHeroAvatarEye", InitHeroAvatarEye);
//	READ_INT_FUN_OTHER("InitHeroAvatarNose", InitHeroAvatarNose);
//	READ_INT_FUN_OTHER("InitHeroAvatarMouth", InitHeroAvatarMouth);
	return true;
}
