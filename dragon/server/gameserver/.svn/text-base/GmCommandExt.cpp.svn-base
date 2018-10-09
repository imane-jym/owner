#include "GmCommandExt.h"
#include "DatabaseMysql.h"
#include "CenterDBCtrl.h"
#include "World.h"
#include "Role.h"
#include "Util.h"
#include "ShardingDB.h"
#include "QueryResult.h"
#include "Other.h"
#include "Role.h"
#include "Other.h"
#include "CsvReader.h"
#include "EnumDefines.h"
#include "Notice.h"

extern CShardingDB WorldDb;
extern std::string g_strConfigPath;
//extern ConfigManager 	configManager;

////////// factory impl ///////////////

GmCommand* GmCommandFactory::Create(
		uint32				dwAutoId,
		std::string&		strOpr,
		GmCommandTargetType	eTargetType,
		uint64				dwTargetId,
		uint32				dwStartTime,
		uint32				dwEndTime,
		std::string&		strBackup,
		GmCommandStatus		eStatus,
		std::string&		strParams )
{
	GmCommand* ret = 0;

	if (strOpr == "cancel_gm_command")
		ret = new CancelCommand();
	else if ( strOpr == "reload" )
		ret = new ReloadConfigCommand();
	else if ( strOpr == "roleauth" )
		ret = new SetRoleAuth();
	else if ( strOpr == "setserver" )
		ret = new SetServer();
//	else if ( strOpr == "forcecancel" )
//		ret = new ForceCancel();
	else if ( strOpr == "whitelist" )
		ret = new WhiteList();
	else if ( strOpr == "noticectrl" )
		ret = new NoticeCtrl();

	if ( ret )
	{
		ret->m_dwAutoId 	= dwAutoId;
		ret->m_strOpr		= strOpr;
		ret->m_eTargetType	= eTargetType;
		ret->m_dwTargetId	= dwTargetId;
		ret->m_dwStartTime	= dwStartTime;
		ret->m_dwEndTime	= dwEndTime;
		ret->m_strBackup	= strBackup;
		ret->m_eStatus		= eStatus;
		ret->m_strParams	= strParams;

		// fix
		if ( eStatus == E_GM_COMMAND_STATUS_PENDING || eStatus == E_GM_COMMAND_STATUS_RUNNING )
		{
			// when user update params, error will happen
			if ( !(ret->Validate()) ) // read param again
			{
				CenterDBCtrl::UpdateErrorstr(ret);
			}
		}
	}

	return ret;
}

bool GmCommandFactory::CheckTargetType( uint8 byTargetType, uint64 dwTargetId )
{
	if ( byTargetType == E_GM_COMMAND_TARGET_TYPE_SERVER )
	{
//		return (uint16)dwTargetId == sWorld->GetServerId();
		return sWorld->IsTarget((uint32)dwTargetId);
	}
	else if ( byTargetType == E_GM_COMMAND_TARGET_TYPE_ROLE )
	{
		DatabaseMysql * mysql = WorldDb.GetDBConnection(0);
		QueryResult* result = mysql->PQuery(
			"select user_id from user_login where user_id=%u", (uint32)dwTargetId
		);
		if ( result )
		{
			delete result;
			return true;
		}
		return false;
	}
	else if ( byTargetType == E_GM_COMMAND_TARGET_TYPE_PASSPORT )
	{
		return false;
	}
	else
	{
		return false;
	}
}

///////////////////////////////////
// cancel_gm_command [gm_auto_id]

bool CancelCommand::Validate()
{
	RETURN_FALSE_IF_TARGET_IS_PASSPORT;
	RETURN_FALSE_IF_TARGET_IS_ROLE;
	RETURN_FALSE_IF_PARAMS_SIZE_INVALID( ==, 1 );

	m_dwGmAutoId = GET_CMD_PARAM_INT( 0 );
	if ( m_dwGmAutoId == GetAutoId() || !CenterDBCtrl::HasGmCommand( m_dwGmAutoId ) )
	{
		SetErrorMsg( "Command Not Found" );
		return false;
	}
	return true;
}

bool CancelCommand::Trigger()
{
	if ( !CenterDBCtrl::CancelGmCommand( m_dwGmAutoId ) )
	{
//		SetErrorMsg( "Error When Cancel" );
		return false;
	}
	return true;
}

bool CancelCommand::Complete()
{
	return true;
}

// reload config impl //////////////
// reload

bool ReloadConfigCommand::Validate()
{
	RETURN_FALSE_IF_TARGET_IS_PASSPORT;
	RETURN_FALSE_IF_TARGET_IS_ROLE;
	RETURN_FALSE_IF_PARAMS_SIZE_INVALID( ==, 1 );

	m_strTable = GET_CMD_PARAM_STRING(0);
	if (!ConfValid(g_strConfigPath, m_strTable))
	{
		SetErrorMsg("csv config valid fail");
		return false;
	}
	return true;
}

bool ReloadConfigCommand::Trigger()
{
	if ( !ConfReload(g_strConfigPath, m_strTable) )
	{
		SetErrorMsg( "Reload Config fail" );
		return false;
	}
	return true;
}

bool ReloadConfigCommand::Complete()
{
	return true;
}

///////////////////////////////////////
// set_role_auth [auth] [gm]
bool SetRoleAuth::Validate()
{
	RETURN_FALSE_IF_TARGET_IS_PASSPORT;
	RETURN_FALSE_IF_TARGET_IS_SERVER;
	RETURN_FALSE_IF_PARAMS_SIZE_INVALID( ==, 2 );

	gm = GET_CMD_PARAM_INT(0);
	limit = GET_CMD_PARAM_INT(1);

	return true;
}

bool SetRoleAuth::Trigger()
{
//	RoleBase *p = (RoleBase *)sWorld->GetRoleBase(GetTargetId());
	uint8_t byStatus;
//	p->byStatus = gm > 0 ? SET_YES_GM(p->byStatus) : SET_NO_GM(p->byStatus);
//	p->byStatus = limit > 0 ? SET_YES_LIMIT_LOGIN(p->byStatus) : SET_NO_LIMIT_LOGIN(p->byStatus);
	
	CRole *pCRole = sWorld->FindUserRole(GetTargetId());
	if (pCRole != NULL)
	{
		byStatus = pCRole->GetbyStatus();
		byStatus = gm > 0 ? SET_YES_GM(byStatus) : SET_NO_GM(byStatus);
		byStatus = limit > 0 ? SET_YES_LIMIT_LOGIN(byStatus) : SET_NO_LIMIT_LOGIN(byStatus);
		pCRole->SetbyStatus(byStatus);
		pCRole->SendProUpdate();
	}
	else
	{
		CRoleBase base;
		if (!base.Init(GetTargetId()))
		{
			SetErrorMsg( format_error("base init fail accountid %u", GetTargetId()) );
			return false;
		}
		byStatus = base.GetbyStatus();
		byStatus = gm > 0 ? SET_YES_GM(byStatus) : SET_NO_GM(byStatus);
		byStatus = limit > 0 ? SET_YES_LIMIT_LOGIN(byStatus) : SET_NO_LIMIT_LOGIN(byStatus);
		base.SetbyStatus(byStatus);

		base.SaveData();
		uint8_t gm = IS_GM(byStatus);
		uint8_t forbid = IS_LIMIT_LOGIN(byStatus);
		CenterDBCtrl::UpdateRoleGmAuth(GetTargetId(), gm);
		CenterDBCtrl::UpdateRoleForbidAuth(GetTargetId(), forbid); 
	}
	return true;
}

bool SetRoleAuth::Complete()
{
	return true;
}

///////////////////////////////////
// setserver [status] [is_new] [can_login] [name] [domain] [res_url]

bool SetServer::Validate()
{
	RETURN_FALSE_IF_TARGET_IS_PASSPORT;
	RETURN_FALSE_IF_TARGET_IS_ROLE;
	RETURN_FALSE_IF_PARAMS_SIZE_INVALID( ==, 6);
	
	m_areaid = GetTargetId();
	m_status = GET_CMD_PARAM_INT(0); 
	m_new = GET_CMD_PARAM_INT(1); 
	m_canlogin = GET_CMD_PARAM_INT(2); 
	m_name = GET_CMD_PARAM_STRING(3); 
	m_domain = GET_CMD_PARAM_STRING(4); 
	m_resurl = GET_CMD_PARAM_STRING(5); 
	return true;
}

bool SetServer::Trigger()
{
	std::map<uint32, SServerData> &Server = sWorld->GetServerList();
	if (Server.find(m_areaid) != Server.end())
	{
		if (m_canlogin != 255)
			Server[m_areaid].canlogin = m_canlogin;
		if (m_status != 255)
			Server[m_areaid].status = m_status;
		if (m_new != 255)
			Server[m_areaid].isnew = m_new;
		if (m_name != "" && m_name != "0")
			Server[m_areaid].servername = m_name;
		if (m_domain != "" && m_domain != "0")
			Server[m_areaid].domain = m_domain;
		if (m_resurl != "" && m_resurl != "0")
			Server[m_areaid].resurl = m_resurl;
//		IME_ERROR("m_name %s", m_name.c_str());
		return true;
	}
	else
	{
		SetErrorMsg(format_error("area_id is not unvalid %u", m_areaid));
		return false;
	}
	return true;
}

bool SetServer::Complete()
{
	return true;
}

///////////////////////////////////
// ForceCancel [index]

bool ForceCancel::Validate()
{
	RETURN_FALSE_IF_TARGET_IS_PASSPORT;
	RETURN_FALSE_IF_TARGET_IS_ROLE;
	RETURN_FALSE_IF_PARAMS_SIZE_INVALID( ==, 1);
	
	m_activeIndex = GET_CMD_PARAM_INT(0); 
	return true;
}

bool ForceCancel::Trigger()
{
//	std::string error = "";
//	CActiveCtrl::DelActive(m_activeIndex, error);
//	if (error != "")
//	{
//		SetErrorMsg(error);
//		return false;
//	}
	return true;
}

bool ForceCancel::Complete()
{
	return true;
}

///////////////////////////////////
// WhiteList [useridlist]

bool WhiteList::Validate()
{
	RETURN_FALSE_IF_TARGET_IS_PASSPORT;
	RETURN_FALSE_IF_TARGET_IS_ROLE;
	RETURN_FALSE_IF_PARAMS_SIZE_INVALID( ==, 1);
	
	std::string tmp = GET_CMD_PARAM_STRING(0); 
	CUtil::StrSplit(tmp, ",", m_vecUserid);
	return true;
}

bool WhiteList::Trigger()
{
	sWorld->SetWhiteList(m_vecUserid);
	return true;
}

bool WhiteList::Complete()
{
	return true;
}

///////////////////////////////////
// noticectrl [choose] [notice_type] [content]

bool NoticeCtrl::Validate()
{
	RETURN_FALSE_IF_TARGET_IS_PASSPORT;
	RETURN_FALSE_IF_TARGET_IS_ROLE;
	RETURN_FALSE_IF_PARAMS_SIZE_INVALID( ==, 3);
	
	m_byChoose = GET_CMD_PARAM_INT(0);
	m_byChatType = GET_CMD_PARAM_INT(1);
	m_strContent = GET_CMD_PARAM_STRING(2);
	return true;
}

bool NoticeCtrl::Trigger()
{
	if (m_byChoose == 0)
	{
		SWorldChat tmp;
		tmp.choose = m_byChatType;
		tmp.userid = 0;
		tmp.username = GlobalConfig::NoticeTypeName;
		tmp.content = m_strContent;
		tmp.viplv = 0;
		WorldPacket info;
		sWorld->PkgWorldChat(tmp, info);
//		sWorld->SendPkgToAll(info);	
		sSessCtrl->SendPkgToAll(info);	
	}
	else
	{
		sWorld->GetCNotice()->DiyNotice(m_strContent);
	}
	return true;
}

bool NoticeCtrl::Complete()
{
	return true;
}
