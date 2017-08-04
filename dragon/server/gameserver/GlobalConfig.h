#ifndef _GLOBAL_CONFIG_H
#define _GLOBAL_CONFIG_H


#include <string>
#include <vector>
#include "Defines.h"

class CRole;
class GlobalConfig
{
public:
	//初始化 全局参数
	static bool Init(std::string strPath);
	
	static void SendData(CRole *pCRole);
	//section test

	static std::string strTestName;		// XXX的名字
	static float fTestFloat;			// XXX参数 用于XXX
	static int nTestInt;				// XXX参数 用于XXX
	static bool bTestBool;				// XXX参数 用于XXX
	
	static int EnergyRate;
	static int InitCoin;
	static int InitDollar;
	static int WorldBroadCD;
	static std::string NoticeTypeName;
	static int FreeMaxVipLevel;

//	static int InitHeroAvatarHair;
//	static int InitHeroAvatarEye;
//	static int InitHeroAvatarNose;
//	static int InitHeroAvatarMouth;

private:

};

#endif
