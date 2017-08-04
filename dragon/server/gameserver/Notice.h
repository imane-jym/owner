/*
 * =====================================================================================
 *
 *       Filename:  Notice.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月24日 11时24分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _NOTICE_H_
#define _NOTICE_H_

#include <stdint.h>
#include "WorldPacket.h"
/*
 * =====================================================================================
 *        Class:  CNotice
 *  Description:  
 * =====================================================================================
 */
class CRole;
class CNotice
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		CNotice ();                             /* constructor */

		bool Init();
		void SaveData();
		/* ====================  ACCESSORS     ======================================= */

		/* ====================  OPERATORS     ======================================= */
		void DiyNotice(std::string content);

		void AddNotice(const WorldPacket &packet);
		void HandlerBroadCast(CRole *pCRole);
		void HandlerSendSysBroadCast();

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */
		WorldPacket m_pkg;
		WorldPacket m_pkgVip;
		std::list<WorldPacket> m_lstPkg;
//		std::list<WorldPacket> m_lstPkgVip;
		uint32_t m_userindex;
//		uint32_t m_userindexvip;
		WorldPacket m_LastPkgVip;

}; /* -----  end of class CNotice  ----- */

#endif
