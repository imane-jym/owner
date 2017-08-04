/*
 * =====================================================================================
 *
 *       Filename:  hero.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/29/2014 02:56:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Hero.h"
#include "Role.h"
#include "CommonConfig.h"
#include "ConfigData.h"

CHero::CHero()
{
	SetdwIndex(0);
}


CHero::~CHero ()
{
	return ;
}		/* -----  end of method CHero::~CHero  ----- */


int
CHero::Init (CRole *pCRole, ByteBuffer &by)
{
	m_pCRole = pCRole;
	if (Serilize(by))
	{
		IME_ERROR("serilize data fail userid %u", m_pCRole->GetdwAccountId());
		return -1;
	}
	if (LoadConf())
	{
		IME_ERROR("load conf fail userid %u", m_pCRole->GetdwAccountId());
		return -1;
	}
	if (Calculate())
	{
		IME_ERROR("calculate data fail userid %u", m_pCRole->GetdwAccountId());
		return -1;
	}
	return 0;
}		/* -----  end of method CHero::Init  ----- */

int CHero::Create(CRole *pCRole, uint32_t index)
{
	m_pCRole = pCRole;
	
	m_dwIndex = index;
	m_dwObjId = index;
	m_wAvatarHair = 0;
	m_wAvatarEye = 0; 
	m_wAvatarNose = 0;
	m_wAvatarMouth = 0;
	m_dwExp = 0;
	m_wLevel = 1;

	if (LoadConf())
	{
		IME_ERROR("load conf fail userid %u", m_pCRole->GetdwAccountId());
		return -1;
	}
	if (Calculate())
	{
		IME_ERROR("calculate data fail userid %u", m_pCRole->GetdwAccountId());
		return -1;
	}
	return 0;
}

int
CHero::Serilize (ByteBuffer &byte)
{
	byte >> m_dwObjId;
	byte >> m_dwIndex;
	byte >> m_wAvatarHair;
	byte >> m_wAvatarEye;
	byte >> m_wAvatarNose;
	byte >> m_wAvatarMouth;
	byte >> m_dwExp;
	byte >> m_wLevel;
	return 0;
}		/* -----  end of method CHero::Serilize  ----- */

int
CHero::DeSerilize (ByteBuffer &byte)
{
	byte << m_dwObjId;
	byte << m_dwIndex;
	byte << m_wAvatarHair;
	byte << m_wAvatarEye;
	byte << m_wAvatarNose;
	byte << m_wAvatarMouth;
	byte << m_dwExp;
	byte << m_wLevel;
	return 0;
}		/* -----  end of method CHero::DeSerilize  ----- */

int
CHero::LoadConf ()
{
	const STC_CONF_HERO *pConf = CConfHero::Find(GetdwIndex());
	if (pConf == NULL)
	{
		IME_ERROR("load hero csv fail index %u", GetdwIndex());
		return -1;
	}

	SetwCombatPosition(pConf->dwPos);
	SetwProfession(pConf->dwJob);
	SetdwExpGrow(pConf->dwExp);
	SetdwLevelLimit(pConf->dwLevelLimit);
	SetdwAttackInit(pConf->dwAttack);
	SetdwAttackGrow(pConf->dwAttackGrow);
	SetdwDefenceInit(pConf->dwDefence);
	SetdwDefenceGrow(pConf->dwDefenceGrow);
	SetdwStrengthInit(pConf->dwStrong);
	SetdwStrengthGrow(pConf->dwStrongGrow);
	SetdwHealInit(pConf->dwLifereconver);
	SetdwHealGrow(pConf->dwLifereconverGrow);
	SetdwPowerRecoverInit(pConf->dwRecover);
	SetdwPowerRecoverGrow(pConf->dwRecoverGrow);
	SetdwAttackSpeed(pConf->dwAttackSpeed);
	SetdwAttackTime(pConf->dwAttackInterval);
	SetdwDodge(pConf->dwDodge);
	SetdwCrit(pConf->dwCrit);
	SetdwCritPower(pConf->dwCritValue);
	SetdwHit(pConf->dwHitratio);
	SetdwSuckBlood(pConf->dwSuckblood);
	SetdwAttackNormal(pConf->dwSkillId[0]);

	return 0;
}		/* -----  end of method CHero::LoadConf  ----- */

int
CHero::Calculate ()
{
	uint32_t lv;
	uint32_t exp;
	CConfHeroExp::GetResult(GetwLevel(), GetdwExp(), lv, exp, GetdwExpGrow() / 100.0);
	SetdwExp(exp);
	SetwLevel(lv);

	SetdwAttack( CALCULATE_HERO_ABILITY(GetdwAttackGrow(), lv, GetdwAttackInit()) );
	SetdwDefence( CALCULATE_HERO_ABILITY(GetdwDefenceGrow(), lv, GetdwDefenceInit()) );
	SetdwStrength( CALCULATE_HERO_ABILITY(GetdwStrengthGrow(), lv, GetdwStrengthInit()) );
	SetdwHeal( CALCULATE_HERO_ABILITY(GetdwHealGrow(), lv, GetdwHealInit()) );
	SetdwPowerRecover( CALCULATE_HERO_ABILITY(GetdwPowerRecoverGrow(), lv, GetdwPowerRecoverInit()) );
	return 0;
}		/* -----  end of method CHero::Calculate  ----- */

void
CHero::PkgProperty (ByteBuffer &by)
{
	by << GetdwObjId();
	by << GetdwIndex();
	by << m_wAvatarHair;
	by << m_wAvatarEye;
	by << m_wAvatarNose;
	by << m_wAvatarMouth;
	by << m_dwExp;
	by << m_wLevel;

	by << m_wCombatPosition;
	by << m_wProfession;
	by << m_dwExpGrow;
	by << m_dwLevelLimit;
	by << m_dwAttack;
	by << m_dwAttackGrow;
	by << m_dwDefence;
	by << m_dwDefenceGrow;
	by << m_dwStrength;
	by << m_dwStrengthGrow;
	by << m_dwHeal;
	by << m_dwHealGrow;
	by << m_dwPowerRecover;
	by << m_dwPowerRecoverGrow;
	by << m_dwAttackSpeed;
	by << m_dwAttackTime;
	by << m_dwDodge;
	by << m_dwCrit;
	by << m_dwCritPower;
	by << m_dwHit;
	by << m_dwSuckBlood;
	by << m_dwAttackNormal;
	by << CConfHeroExp::GetMaxExpIntervalLv(GetwLevel(), GetdwExpGrow());

	return ;
}		/* -----  end of method CHero::PkgProperty  ----- */

int CHero::AddExp(uint32_t exp)
{
	if (GetwLevel() >= CConfHeroExp::GetMaxLevel())
	{
		if (GetdwExp() < CConfHeroExp::GetMaxExpIntervalLv(GetwLevel(), GetdwExpGrow()))
		{
			if (GetdwExp() + exp > CConfHeroExp::GetMaxExpIntervalLv(GetwLevel(), GetdwExpGrow()))
			{
				IME_DEBUG("exp overload max exp");
				SetdwExp(CConfHeroExp::GetMaxExpIntervalLv(GetwLevel(), GetdwExpGrow()));
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
