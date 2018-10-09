/*
 * =====================================================================================
 *
 *       Filename:  Store.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/22/2014 04:45:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _STORE_H_
#define _STORE_H_

#include <map>
#include <stdint.h>
#include "WorldPacket.h"

struct STC_CONF_GACHA;
struct SProduct;
class CRole;
/*
 * =====================================================================================
 *        Class:  CShop
 *  Description:  
 * =====================================================================================
 */
class CStore
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		CStore ();                             /* constructor */
		~CStore ();
		int Init(CRole *pCRole);

		/* ====================  OPERATORS     ======================================= */
		bool LoadData();
		int SaveData();
		int SerilizeDB(ByteBuffer &byte);
		int DeSerilizeDB(ByteBuffer &byte);
		void AddItem(uint32_t index, int source, uint32_t number = 1);
		int DelItem(uint32_t index, int source, uint32_t number = 1);
		bool IsHave(uint32_t index, uint32_t number = 1);

		bool IsHaveBoxAndKey(uint32_t CombineId);
		int DelItemByFuncType(uint32_t Functype, uint32_t CombineId, uint32_t &shopid);

		void PreDataForUpgrade(std::map<uint32_t, uint32_t> &map) {map = m_mapShop;};

		void HandlerStoreData(WorldPacket &pkg);
		void HandlerShopInfo(uint32_t index = 0);
		void HandlerBuy (WorldPacket &pkg);
		void HandlerShopUse(WorldPacket &pkg);
		void HandlerBuyDelCD(WorldPacket &pkg);
		void HandlerShopUseCancel(WorldPacket &pkg);

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */
		CRole *m_pCRole;
		bool m_IsInit;

		/* ====================  DATA MEMBERS  ======================================= */
		uint32_t m_kind;

}; /* -----  end of class CShop  ----- */

#endif
