/*
 *  RoleBase.h
 *
 *  Created on: 2014-04-21
 *      Author: imane
 */

#include "RoleBase.h"
#include "World.h"
#include "GlobalConfig.h"
#include "DBCtrl.h"
#include "ConfigData.h"

CRoleBase::CRoleBase():m_pBase(NULL)
{

}

CRoleBase::~CRoleBase()
{

}

bool CRoleBase::Init(uint32_t accountid)
{
	m_pBase = (RoleBase *)sWorld->GetRoleBase(accountid);
	if (!m_pBase)
		return false;
	//新账号初始化
	if (GetwLevel() == 0)
	{
	}
	else
	{

		uint32_t now = time(NULL);
		uint32_t count = 0;
		if (now >= GetdwEnergyTime())
		{
			count = (now - GetdwEnergyTime()) / GlobalConfig::EnergyRate;
			ChangeEnergy(count);
			SetdwEnergyTime(GlobalConfig::EnergyRate * count + GetdwEnergyTime());
		}
	}
	return true;
}

void CRoleBase::SaveData()
{
	CDBCtrl::UpdateUserBaseData(*m_pBase);
}

int CRoleBase::Calculate()
{
	uint32_t lv;
	uint32_t exp;
	CConfRole::GetResult(GetwLevel(), GetdwExp(), lv, exp);
	SetdwExp(exp);
	SetwLevel(lv);
	CConfVip::GetResult(INIT_VIP_LEVEL, GetdwVipTotalExp(), lv, exp);
	lv = lv > (uint32_t)GlobalConfig::FreeMaxVipLevel ? GlobalConfig::FreeMaxVipLevel : lv;
	if (lv > GetdwVipLv())
		SetdwVipLv(lv);
	return 0;
}

int CRoleBase::AddExp(uint32_t exp)
{
	if (GetwLevel() >= CConfRole::GetMaxLevel())
	{
		if (GetdwExp() < CConfRole::GetMaxExpIntervalLv(GetwLevel()))
		{
			if (GetdwExp() + exp > CConfRole::GetMaxExpIntervalLv(GetwLevel()))
			{
				IME_DEBUG("exp overload max exp");
				SetdwExp(CConfRole::GetMaxExpIntervalLv(GetwLevel()));
			}
			else
			{
				SetdwExp(GetdwExp() + exp);
			}
		}
	}
	else
	{
		SetdwExp(GetdwExp() + exp);
	}
	return 0;
}

int CRoleBase::ChangeEnergy(int32_t energy)
{
	STC_CONF_ROLE *pConf = CConfRole::Find(GetwLevel());
	if (!pConf)
		return -1;
	int32_t temp = (int)GetdwEnergy() + energy;
	if (energy < 0)
	{
		SetdwEnergy(temp < 0 ? 0 : temp);
	}
	else
	{
		if (GetdwEnergy() < pConf->dwEnergyLimit)
		{
			SetdwEnergy((uint32_t)temp > pConf->dwEnergyLimit ? pConf->dwEnergyLimit : temp);
		}
	}
	return 0;
}

int CRoleBase::ChangeEnergyNoLimit(int32_t energy)
{           
	int32_t temp = (int)GetdwEnergy() + energy;
	if (temp < 0) temp = 0;
	SetdwEnergy(temp);
	return 0;
}       

int CRoleBase::ChangeCoin(int32_t coin, int source, uint64_t cir)
{
	if (coin == 0) return 0;
	int64_t c = GetlCoin() + coin;
	SetlCoin(c < 0 ? 0 : c);
	std::string opt = coin >= 0 ? "opt=add" : "opt=del";
	IME_CHAR_LOG(GetdwAccountId(), "RESOURCE", "type=property|%s|character=%u|index=%u|number=%d|source=%d|circulateid=%llu", opt.c_str(), GetdwAccountId(), RES_COIN, abs(coin), source, (unsigned long long)cir);
	return 0;
}

int CRoleBase::ChangeDollar(int32_t dollar, int source, uint64_t cir)
{
	if (dollar == 0) return 0;
//	IME_LOG("add dollar %u", dollar);
	int64_t d = dollar + GetlDollar();	
	SetlDollar(d < 0 ? 0 : d);
	//todo some DB record
	std::string opt = dollar >= 0 ? "opt=add" : "opt=del";
	IME_CHAR_LOG(GetdwAccountId(), "RESOURCE", "type=property|%s|character=%u|index=%u|number=%d|source=%d|circulateid=%llu", opt.c_str(), GetdwAccountId(), RES_DOLLAR, abs(dollar), source, (unsigned long long)cir);
	return 0;
}

int CRoleBase::ChangeVipExp(int32_t exp)
{
	if (exp == 0) return 0;
	int32_t temp = (int)GetdwVipTotalExp() + exp;
	SetdwVipTotalExp(temp > 0 ? temp : 0);
	return 0;
	//todo some DB record
}

