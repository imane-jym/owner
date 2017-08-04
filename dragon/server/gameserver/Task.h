/*
 * =====================================================================================
 *
 *       Filename:  Task.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/14/2014 07:05:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <map>
#include "CommonType.h"
#include "WorldPacket.h"

class CRole;
/*
 * =====================================================================================
 *        Class:  CTask
 *  Description:  
 * =====================================================================================
 */
class CTask
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		CTask ();                             /* constructor */
		~CTask ();
		int Init(CRole *pCRole);
		void SerilizeDB(ByteBuffer &pkg);
		void DeSerilizeDB(ByteBuffer &pkg);
		int LoadData();
		void SaveData();
		void OnTimer5s();

		/* ====================  ACCESSORS     ======================================= */

		/* ====================  MUTATORS      ======================================= */

		/* ====================  OPERATORS     ======================================= */
		void HandlerCombatPreview(WorldPacket &packet);
		void HandlerCombatResult(WorldPacket &packet);
		void HandlerTaskInfo(uint32_t index = 0);

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */
		CRole *m_pCRole;
		std::map<uint32_t, TaskData> m_mapTask;
		ByteBuffer m_PreviewCombatPacket;
}; /* -----  end of class CTask  ----- */

