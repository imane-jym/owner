/*
 * =====================================================================================
 *
 *       Filename:  Other.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年02月04日 13时21分11秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Other.h"
#include "DBCtrl.h"
#include "ConfigData.h"
#include "Util.h"
#include "ErrorMsg.h"
#include "CmdDefine.h"
#include "Role.h"
#include "World.h"
#include "EnumDefines.h"
#include "CommonType.h"
#include "CsvReader.h"
#include "CenterDBCtrl.h"

CAnnouncement::CAnnouncement()
{

}

bool CAnnouncement::Init()
{
//	if (!CDBCtrl::GetAnnouncementData(m_vecContent))
//	if (!CenterDBCtrl::GetNoticeByType(E_NOTICE_USE_TYPE_GAME, m_vecContent))
//	{
//		IME_ERROR("init announcemenetdata fail");
//		return false;
//	}
	CenterDBCtrl::GetNoticeByType(E_NOTICE_USE_TYPE_GAME, m_vecContent);
	return true;
}

void
CAnnouncement::HandlerInfo (CRole *pCRole)
{
	WorldPacket pkg(CMD_SC_ANNOUNCEMENT_INFO);
	pkg << (uint16_t) m_vecContent.size();
	for (unsigned int i = 0; i < m_vecContent.size(); i++)
	{
		pkg << m_vecContent[i];
	}
	pCRole->SendPacket(&pkg);
	return ;
}		/* -----  end of method CAnnouncement::HandlerInfo  ----- */

//void
//CAnnouncement::HandlerUpdateContent (const std::string &strAd, uint32 dwId)
//{
//	if (dwId > 10)
//	{
//		return;
//	}
//	m_vecContent[dwId - 1] = strAd;
//	CDBCtrl::SaveAnnouncementData(strAd, dwId);
//
//	WorldPacket pkg(CMD_SC_ANNOUNCEMENT_INFO);
//	pkg << (uint16_t) m_vecContent.size();
//	for (int i = 0; i < m_vecContent.size(); i++)
//	{
//		pkg << m_vecContent[i];
//	}
//	sSessCtrl->SendPkgToAll(pkg);
//	return ;
//}		/* -----  end of method CAnnouncement::HandlerUpdateContent  ----- */

