

#ifndef _WORLD_H
#define _WORLD_H
#include "Defines.h"
#include "zthread/ZThread.h"
#include "zthread/FastMutex.h"
#include "zthread/LockedQueue.h"
#include "zthread/Thread.h"
#include "Timer.h"
#include "stdint.h"
#include "CommonType.h"
#include "SessCtrl.h"
#include <map>
#include <vector>
#include <set>

#define MAKE_FIND_GROUPID(userid,groupid) ((uint64_t)userid << 32 | groupid)

//class CUserSession;
//class CRelayClientSession;
class CRole;
class CHandlerPlayersession;
class WorldPacket;
class CNotice;
class CAnnouncement;
class CRoleBase;

class CWorld
{
public:

	/// Timers for different object refresh rates
	enum WorldTimers
	{
	    WUPDATE_PINGDB,
		WUPDATE_30min,
		WUPDATE_LOGIN,
		WUPDATE_10min,
		WUPDATE_1s,
		WUPDATE_CHARGE,
	    WUPDATE_COUNT
	};
	
	CWorld();
	~CWorld();
	
	static CWorld * GetInstance();
	typedef std::map<uint32, CHandlerPlayersession*> MapSessionByUserId;	// map<AccountId , ... > ͨ
	bool InitSettings();

	void AddUserAuth(uint32 dwUserId, CHandlerPlayersession* pSession);
	void DelUserAuth(uint32 dwUserId);
	CRole* FindUserRole(uint32 dwUserId);
	CHandlerPlayersession* FindSess(uint32 dwUserId);
	MapSessionByUserId& GetUserMap() { return m_mapUserAuth; }
	void AllOffline();

	void Update1min();
	void Update10min();
	void Update30min();
	void UpdateLoginInfo();
	void Update1s();
	void UpdateCharge();

	void SetIp(std::string &strIp);
	void SetPort(int nPort);
	void SetServerId(std::string strServerId);
	bool IsTarget(uint32_t serverid)
	{
		return (find(m_vecServerId.begin(), m_vecServerId.end(), serverid) != m_vecServerId.end());
	}
	std::vector<uint32_t> GetServerId()
	{
		return m_vecServerId;
	}

	uint32 GetOnlineNum();

	void GetRoleList(std::vector<CRole*>& vecRole);

	void SaveAllData();

	void AddWorldChat(const SWorldChat &tmp);
	void HandlerWorldChatInfo(CRole *pCRole);
	void PkgWorldChat(SWorldChat tmp, WorldPacket &info);

	bool IsWhiteList(uint32_t userid)
	{
		return std::find(m_vecWhiteList.begin(), m_vecWhiteList.end(), userid) != m_vecWhiteList.end() ? true : false;
	}
	void SetWhiteList(std::vector<uint32_t> vec)
	{
		m_vecWhiteList = vec;
	}

	CNotice *GetCNotice() {return m_pCNotice;}
	CAnnouncement *GetCAnnouncement() {return m_pCAnnouncement;}

	std::map<uint32_t, SServerData>& GetServerList() {return m_mapServer;}

	bool IsExists(std::string username)
	{
		return (m_setAllUserName.find(username) != m_setAllUserName.end());
	}
	void DelUserName(std::string username)
	{
		m_setAllUserName.erase(username);
	}
	void InsertUserName(std::string username)
	{
		m_setAllUserName.insert(username);
	}
	void AddRoleBase(const RoleBase &data);
	const RoleBase *GetRoleBase(uint32_t dwAccountId);

private:
	static CWorld * m_pInstance;

	IntervalTimer m_timers[WUPDATE_COUNT];
	MapSessionByUserId m_mapUserAuth;

	std::string m_strIp;
	int m_nPort;
	std::vector<uint32_t> m_vecServerId;
	std::map<uint32, SServerData> m_mapServer;

	CNotice *m_pCNotice;
	CAnnouncement *m_pCAnnouncement;

	std::list<SWorldChat> m_lstWorldBroadCast;
	std::vector<uint32_t> m_vecWhiteList;

	std::set<std::string> m_setAllUserName;

	std::map<uint32_t, RoleBase> m_mapRoleBase;
};
//todo singleton
#define sWorld (CWorld::GetInstance())
#endif

