/*
 * =====================================================================================
 *
 *       Filename:  Hero.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/29/2014 02:56:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _HERO_H_
#define _HERO_H_
#include <map>
#include <stdint.h>
#include "ByteBuffer.h"
#include "Log.h"
#include "stdint.h"
#include "CommonType.h"

class CRole;
/*
 * =====================================================================================
 *        Class:  CHero
 *  Description:  
 * =====================================================================================
 */
class CHero
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		CHero ();                             /* constructor */
		~CHero ();
		int Init(CRole *pCRole, ByteBuffer &by);
		int Create(CRole *pCRole, uint32_t index);
		int Serilize(ByteBuffer &byte);
		int DeSerilize(ByteBuffer &byte);
		int LoadConf();
		int Calculate();

		void PkgProperty(ByteBuffer &by);

		/* ====================  ACCESSORS     ======================================= */
		PROPERTY_OPT(uint32_t, dwObjId);
		PROPERTY_OPT(uint32_t, dwIndex);
		PROPERTY_OPT(uint16_t, wAvatarHair);
		PROPERTY_OPT(uint16_t, wAvatarEye);
		PROPERTY_OPT(uint16_t, wAvatarNose);
		PROPERTY_OPT(uint16_t, wAvatarMouth);
		PROPERTY_OPT(uint32_t, dwExp);
		PROPERTY_OPT(uint16_t, wLevel);

		PROPERTY_OPT(uint16_t, wCombatPosition);
		PROPERTY_OPT(uint16_t, wProfession);
		PROPERTY_OPT(uint32_t, dwExpGrow);
		PROPERTY_OPT(uint16_t, dwLevelLimit);
		PROPERTY_OPT(uint32_t, dwAttack);
		PROPERTY_OPT(uint32_t, dwAttackInit);
		PROPERTY_OPT(uint32_t, dwAttackGrow);
		PROPERTY_OPT(uint32_t, dwDefence);
		PROPERTY_OPT(uint32_t, dwDefenceInit);
		PROPERTY_OPT(uint32_t, dwDefenceGrow);
		PROPERTY_OPT(uint32_t, dwStrength);
		PROPERTY_OPT(uint32_t, dwStrengthInit);
		PROPERTY_OPT(uint32_t, dwStrengthGrow);
		PROPERTY_OPT(uint32_t, dwHeal);
		PROPERTY_OPT(uint32_t, dwHealInit);
		PROPERTY_OPT(uint32_t, dwHealGrow);
		PROPERTY_OPT(uint32_t, dwPowerRecover);
		PROPERTY_OPT(uint32_t, dwPowerRecoverInit);
		PROPERTY_OPT(uint32_t, dwPowerRecoverGrow);
		PROPERTY_OPT(uint32_t, dwAttackSpeed);
		PROPERTY_OPT(uint32_t, dwAttackTime);
		PROPERTY_OPT(uint32_t, dwDodge);
		PROPERTY_OPT(uint32_t, dwCrit);
		PROPERTY_OPT(uint32_t, dwCritPower);
		PROPERTY_OPT(uint32_t, dwHit);
		PROPERTY_OPT(uint32_t, dwSuckBlood);
		PROPERTY_OPT(uint32_t, dwAttackNormal);
		/* ====================  OPERATORS     ======================================= */
		int AddExp(uint32_t exp);

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */
		CRole *m_pCRole;
		uint32_t m_dwObjId;
		uint32_t m_dwIndex;
		uint16_t m_wAvatarHair;
		uint16_t m_wAvatarEye;
		uint16_t m_wAvatarNose;
		uint16_t m_wAvatarMouth;
		uint32_t m_dwExp;
		uint16_t m_wLevel;
		
		uint16_t m_wCombatPosition;
		uint16_t m_wProfession;
		uint32_t m_dwExpGrow;
		uint16_t m_dwLevelLimit;
		uint32_t m_dwAttack;
		uint32_t m_dwAttackInit;
		uint32_t m_dwAttackGrow;
		uint32_t m_dwDefence;
		uint32_t m_dwDefenceInit;
		uint32_t m_dwDefenceGrow;
		uint32_t m_dwStrength;
		uint32_t m_dwStrengthInit;
		uint32_t m_dwStrengthGrow;
		uint32_t m_dwHeal;
		uint32_t m_dwHealInit;
		uint32_t m_dwHealGrow;
		uint32_t m_dwPowerRecover;
		uint32_t m_dwPowerRecoverInit;
		uint32_t m_dwPowerRecoverGrow;
		uint32_t m_dwAttackSpeed;
		uint32_t m_dwAttackTime;
		uint32_t m_dwDodge;
		uint32_t m_dwCrit;
		uint32_t m_dwCritPower;
		uint32_t m_dwHit;
		uint32_t m_dwSuckBlood;
		uint32_t m_dwAttackNormal;

}; /* -----  end of class CHero  ----- */


#endif
