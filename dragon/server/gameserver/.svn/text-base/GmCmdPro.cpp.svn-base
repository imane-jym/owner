/*
 * GmCmdPro.cpp
 *
 *  Created on: 2011-6-23
 *      Author: yq
 */

#include "GmCmdPro.h"
#include "Util.h"
#include "Role.h"
#include <string>
#include <vector>
#include <map>
#include "DBCtrl.h"
#include "CmdInnerDefine.h"
#include "World.h"
#include "ConfigData.h"
#include "GlobalConfig.h"
#include "md5.h"
#include "Other.h"
#include "CenterDBCtrl.h"

extern std::string g_strConfigPath;

CGmCmdPro::MAP_FUNC_GM_CMD CGmCmdPro::m_mapGmFuncs;

void CGmCmdPro::Init()
{
	m_mapGmFuncs.clear();

	m_mapGmFuncs["$test"] = Test;
	m_mapGmFuncs["$lv"] = Level;
	m_mapGmFuncs["$addexp"] = AddExp;
	m_mapGmFuncs["$addenergy"] = AddEnergy;
	m_mapGmFuncs["$addcoin"] = AddCoin;
	m_mapGmFuncs["$adddollar"] = AddDollar;
	m_mapGmFuncs["$viplvup"] = VipLvUp;
	m_mapGmFuncs["$addvipexp"] = AddVipexp;
	m_mapGmFuncs["$charge"] = Charge;
	m_mapGmFuncs["$limitrole"] = LimitRole;
	m_mapGmFuncs["$hero"] = Hero;
}

void CGmCmdPro::PraseCmd(CRole *pRole, const std::string & strContent)
{
	IME_LOG("Gm Cmd[%s]", strContent.c_str());
	IME_CHAR_LOG(0, "ACTION", "desc=[user %u press gm cmd %s]", pRole->GetdwAccountId(), strContent.c_str());
	if (!pRole->IsGM())
	{
		//todo
		IME_ERROR("GM:Role %s is not a gm",pRole->GetstrAccount().c_str());
		return ;
	}

	std::vector<std::string> vecData;
	CUtil::StrSplit(strContent," ",vecData);
	if (vecData.size() >= 1)
	{
		MAP_FUNC_GM_CMD::iterator itr = m_mapGmFuncs.find(vecData[0]);
		if (itr != m_mapGmFuncs.end())
		{
			(*(itr->second))(pRole, vecData);
		}
	}
}

void CGmCmdPro::Test(CRole *pRole, const std::vector<std::string> & vecPara)
{
	//echo test
	if (vecPara.size() > 1)
	{
		std::string strContent;
		for(unsigned int i = 0; i < vecPara.size(); ++i)
			strContent += vecPara[i] + "---";
		//todo
        pRole->SendMsgStr(strContent);
	}
}

void CGmCmdPro::Level(CRole *pRole, const std::vector<std::string> &vecPara)
{
    int lv = atol(vecPara[1].c_str());
	if ((unsigned int)lv <= CConfRole::GetMaxLevel())
	{
		pRole->SetwLevel(lv);
		pRole->SendProUpdate();
	}
}

void CGmCmdPro::AddExp(CRole *pRole, const std::vector<std::string> &vecPara)
{
	if (vecPara.size() < 2)
		return;
    int val = atol(vecPara[1].c_str());
//    unsigned int Exp = pRole->GetdwExp(); 
//    Exp += val;
//    pRole->SetdwExp(Exp);
	pRole->AddExp(val);
	pRole->Calculate();
    pRole->SendProUpdate();
}

void CGmCmdPro::AddEnergy(CRole *pRole, const std::vector<std::string> &vecPara)
{
	if (vecPara.size() < 2)
		return;
    int val = atol(vecPara[1].c_str());
//    unsigned int Energy = pRole->GetdwEnergy(); 
//    Energy += val;
//    pRole->SetdwEnergy(Energy);
	pRole->ChangeEnergyNoLimit(val);
    pRole->SendProUpdate();
}

void CGmCmdPro::AddCoin(CRole *pRole, const std::vector<std::string> &vecPara)
{
	if (vecPara.size() < 2)
		return;
    int val = atol(vecPara[1].c_str());
//    unsigned int Coin = pRole->GetdwCoin(); 
//    Coin += val;
//    pRole->SetdwCoin(Coin);
	if (val == 0) return;
	pRole->ChangeCoin(val, SOURCE_GM);
    pRole->SendProUpdate();

}

void CGmCmdPro::AddDollar(CRole *pRole, const std::vector<std::string> &vecPara)
{
	if (vecPara.size() > 1)
	{
		int32_t val  = atol(vecPara[1].c_str());
		if (val == 0)
			return;
		uint32 type = val > 0 ? E_DC_GM_GIVE : E_DC_GM_DEL;
		uint32 number = abs(val);
		if (val < 0) 
			number = abs(val) > pRole->GetlDollar() ? pRole->GetlDollar() : abs(val);

		uint32_t order_id = pRole->GetNewObjId();

		pRole->ChangeDollar(val, SOURCE_GM);
		pRole->SendProUpdate();
		CDBCtrl::LogShopRecord(pRole->GetdwAccountId(), order_id, number, 0, 1, type);	
	}
}

void CGmCmdPro::VipLvUp(CRole *pRole, const std::vector<std::string> &vecPara)
{
	if (vecPara.size() > 1)
	{
		uint32_t lev = atol(vecPara[1].c_str());
		pRole->SetdwVipLv(lev);
		pRole->Calculate();
		pRole->SendProUpdate();
	}
}

void CGmCmdPro::AddVipexp(CRole *pRole, const std::vector<std::string> &vecPara)
{
	if (vecPara.size() > 1)
	{
		int exp = atol(vecPara[1].c_str());
		pRole->ChangeVipExp(exp);
//		IME_LOG("vip exp %u lv %u", pRole->GetdwVipExp(), pRole->GetwVipLv());
		pRole->Calculate(true);
	}
}

void CGmCmdPro::Charge(CRole *pCRole, const std::vector<std::string> &vecPara)
{
	if (vecPara.size() >= 1)
	{
//		int goodsid = atol(vecPara[1].c_str());
//		STC_CONF_STORE *pConf = CConfStore::Find(goodsid);
//		if (pConf == NULL)
//		{
//			IME_ERROR("can not find this goods %u", goodsid);
//			return;
//		}
//		if (pConf->byObjType != STORE_OBJ_RMB)
//		{
//			IME_ERROR("this goodsid %u is not charge goods", goodsid);
//			return;
//		}
//		CenterDBCtrl::InsertCharge(goodsid, pCRole->GetdwAccountId(), 1);
	}
}

void CGmCmdPro::LimitRole(CRole *pRole, const std::vector<std::string> &vecPara){
	if (vecPara.size() < 2)
			return;
	uint32 userId = atol(vecPara[1].c_str());
	uint32 isLimit = atol(vecPara[2].c_str());
	
	uint8_t byStatus;
	CRole *pCRole = sWorld->FindUserRole(userId);
	if (pCRole != NULL)
	{
		byStatus = pCRole->GetbyStatus();
		byStatus = isLimit > 0 ? SET_YES_LIMIT_LOGIN(byStatus) : SET_NO_LIMIT_LOGIN(byStatus);
		pCRole->SetbyStatus(byStatus);
		pCRole->SendProUpdate();
	}
	else
	{
		CRoleBase base;
		if (!base.Init(userId))
		{
			IME_ERROR( "base init fail accountid %u", userId );
			return;
		}
		byStatus = base.GetbyStatus();
		byStatus = isLimit > 0 ? SET_YES_LIMIT_LOGIN(byStatus) : SET_NO_LIMIT_LOGIN(byStatus);
		base.SetbyStatus(byStatus);

		base.SaveData();
	}
	return;
}

void CGmCmdPro::Hero(CRole *pRole, const std::vector<std::string> &vecPara)
{
	if (vecPara.size() < 1)
			return;
	uint32 pos = atol(vecPara[1].c_str());
	pRole->HeroCome(pos);
}
