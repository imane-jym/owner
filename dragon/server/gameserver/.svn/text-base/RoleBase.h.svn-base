/*
 *  RoleBase.h
 *
 *  Created on: 2011-11-06
 *      Author: hx
 */

#ifndef ROLE_BASE_H_
#define ROLE_BASE_H_

#include <string>
#include <vector>
#include "Defines.h"
#include "CommonType.h"

#define PROPERTY_ROLEBASE(T,name) \
	T Get##name() { return m_pBase->name;}; \
	void Set##name(T name) \
	{ m_pBase->name = name; \
	}; \

class CRoleBase
{
public:
	CRoleBase();

	virtual ~CRoleBase();
	bool Init(uint32_t accountid);
	void SaveData();
	int Calculate();

	PROPERTY_ROLEBASE(uint32_t, dwAccountId);
	PROPERTY_ROLEBASE(std::string, strAccount);
	PROPERTY_ROLEBASE(std::string, strUserName);
	PROPERTY_ROLEBASE(uint16_t, wLevel);
	PROPERTY_ROLEBASE(uint32_t, dwExp);
	PROPERTY_ROLEBASE(uint32_t, dwVipLv);
	PROPERTY_ROLEBASE(uint32_t, dwVipTotalExp);
	PROPERTY_ROLEBASE(uint64_t, lDollar);
	PROPERTY_ROLEBASE(uint64_t, lCoin);
	PROPERTY_ROLEBASE(uint32_t, dwEnergy);
	PROPERTY_ROLEBASE(uint32_t, dwEnergyTime);
	PROPERTY_ROLEBASE(uint32_t, dwVipEndTime);
	PROPERTY_ROLEBASE(uint8_t, byStatus);
	PROPERTY_ROLEBASE(uint32_t, dwTaskPosition);
	PROPERTY_ROLEBASE(std::string, strToken);
	PROPERTY_ROLEBASE(uint32_t, dwGameFlow);

	int AddExp(uint32_t exp);	
	int ChangeEnergy(int32_t energy);
	int ChangeEnergyNoLimit(int32_t energy);
	int ChangeCoin(int32_t coin, int source, uint64_t circulateid = 0);
	int ChangeDollar(int32_t dollar, int source, uint64_t circulateid = 0);
	int ChangeVipExp(int32_t exp);

public:
	RoleBase *m_pBase;
};

#endif
