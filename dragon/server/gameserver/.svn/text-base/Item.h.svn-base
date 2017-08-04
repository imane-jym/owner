/*
 * =====================================================================================
 *
 *       Filename:  Item.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月22日 06时24分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _ITEM_H_
#define _ITEM_H_
#include <map>
#include <stdint.h>
#include "ByteBuffer.h"
#include "Log.h"
#include "stdint.h"
#include "CommonType.h"

class CRole;

class CItemBase 
{	
public:
	CItemBase();
	virtual ~CItemBase();
	virtual int Init(ByteBuffer &by);
	virtual void SerilizeDB(ByteBuffer &by);
	virtual void PkgData(ByteBuffer &by);

	PROPERTY_OPT(uint32_t, dwObjId);
	PROPERTY_OPT(uint32_t, dwNum);
	PROPERTY_OPT(uint16_t, wType);
	PROPERTY_OPT(uint32_t, dwIndex);

private:
	uint32_t m_dwObjId;
	uint32_t m_dwNum;
	uint16_t m_wType;
	uint32_t m_dwIndex;
};

CItemBase *CreateItem(uint32_t dwObjId, uint16_t wtype, uint32_t dwNum, uint32_t index);

#define CREATE_ONE_ITEM(objid, type, number, index, oneby, p)\
p = CreateItem(objid, type, number, index);\
if (p == NULL)\
{\
	IME_ERROR("create item fail objid %u, number %u, type %u", objid, number, type);\
	return -1;\
}\
if (p->Init(oneby))\
{\
	IME_ERROR("init item fail");\
	return -1;\
}

/*
 * =====================================================================================
 *        Class:  CItem
 *  Description:  
 * =====================================================================================
 */
class CItem
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		CItem ();                             /* constructor */
		~CItem ();
		int Init(CRole *pCRole);

		/* ====================  ACCESSORS     ======================================= */
		typedef enum 
		{
			ADD,
			DEL
		} action_t;

		void SetCRole(CRole *pCRole) { m_pCRole = pCRole;};

		/* ====================  OPERATORS     ======================================= */
		bool LoadData();
		int SaveData();
		int SerilizeDB(ByteBuffer &byte);
		int DeSerilizeDB(ByteBuffer &byte);

		void HandlerItemInfo(uint32_t objid = 0);
		int AddItem(uint32_t index, uint32_t &objid, int source, uint64_t cir = 0, uint32_t number = 1);
		int DelItem(uint32_t objid, int source, uint64_t cir = 0, uint32_t number = 1);

		void ItemUpdate(uint32_t objid, uint8_t action, uint32_t number = 1);
		int JudgeItemNumber(uint32_t objid, uint32_t number = 1);
//		int JudgeItemNumberbyIndex(uint32_t index, uint32_t number = 1) { return JudgeItemNumber(index, number); }
		CItemBase *GetItem(uint32_t objid) {if (m_mapItem.find(objid) != m_mapItem.end()) return m_mapItem[objid]; return NULL;}
//		CItemBase *GetItemByIndex(uint32_t index) { return GetItem(index);}

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */
		std::map<uint32_t, CItemBase* > m_mapItem;
		CRole *m_pCRole;
		bool m_IsInit;

}; /* -----  end of class CItem  ----- */

class CItemEquip: public CItemBase
{
public:
	CItemEquip();
	~CItemEquip();
	int Init(ByteBuffer &by);
	void SerilizeDB(ByteBuffer &by);
	void PkgData(ByteBuffer &by);

	int LoadConf();
	int Calculate();

	PROPERTY_OPT(uint16_t, wLevel);
	PROPERTY_OPT(uint16_t, wStarLevel);
	PROPERTY_OPT(uint16_t, wUseLevelLimit);
	PROPERTY_OPT(uint8_t, byProfessionLimit);
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

private:

	uint16_t m_wLevel;
	uint16_t m_wStarLevel;
	uint16_t m_wUseLevelLimit;
	uint8_t m_byProfessionLimit;
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
};

class CItemMisc:public CItemBase
{
public:
	CItemMisc();
	~CItemMisc();
};

#endif
