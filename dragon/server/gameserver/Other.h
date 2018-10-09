/*
 * =====================================================================================
 *
 *       Filename:  Other.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年02月04日 13时21分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _OTHER_H_
#define _OTHER_H_

#include <vector>
#include <set>
#include <stdint.h>
#include "WorldPacket.h"
#include "CommonType.h"
#include "GmCommand.h"
#include "EnumDefines.h"

#define READER_CSV_INT(value) \
		do{\
		value = atol(csv.GetCell(i, j++).c_str());\
		}while(0)

#define READER_CSV_FLOAT(value) \
	do{\
	value = atof(csv.GetCell(i, j++).c_str());\
	}while(0)

#define READER_CSV_STR(value) \
	do{\
		value = csv.GetCell(i, j++);\
	}while(0)

#define IS_READER_CSV_ERROR \
        do{\
            if (csv.GetErrorStr() != "") \
            {\
				IME_ERROR("csv reader fail %s", csv.GetErrorStr().c_str());\
				return false;\
            }\
        }while(0)

class CRole;
/*
 * =====================================================================================
 *        Class:  CAnnouncement
 *  Description:  
 * =====================================================================================
 */
class CAnnouncement
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		CAnnouncement ();                             /* constructor */
		bool Init();

		/* ====================  OPERATORS     ======================================= */
//		void HandlerUpdateContent(const std::string &str, uint32_t dwId);
		void HandlerInfo(CRole *pCRole);

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */
		std::vector<std::string> m_vecContent;
}; /* -----  end of class CAnnouncement  ----- */

#endif
