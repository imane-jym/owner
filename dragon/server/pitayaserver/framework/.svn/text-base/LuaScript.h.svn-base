/*
 * LuaScript.h
 *
 *  Created on: 2011-7-8
 *      Author: yq
 */

#ifndef LUASCRIPT_H_
#define LUASCRIPT_H_

// ---------------------------------------------------------------------------
// FILE NAME				: LuaScript.h
// ---------------------------------------------------------------------------
// DESCRIPTION :
//
// Scripting base class
//
// ---------------------------------------------------------------------------
// VERSION				  : 1.00
// DATE					  : 1-Sep-2005
// AUTHOR					: Richard Shephard
// ---------------------------------------------------------------------------
// LIBRARY INCLUDE FILES

extern "C"
{
#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>
#include <lua5.1/lualib.h>
};

#include <string>
#include "Log.h"

class CLuaRestoreStack
{
public:
	CLuaRestoreStack (lua_State* pState) : m_pState(pState)
	{
		if( pState )
		{
			m_iTop = lua_gettop (m_pState);
		}
	}
	virtual ~CLuaRestoreStack ()
	{
		if( NULL != m_pState )
			lua_settop (m_pState, m_iTop);
	}
private:
	lua_State *m_pState;
	int m_iTop;
};

// Sets the "this" global table that scripts use

class CLuaThis
{
public:
	CLuaThis (lua_State* pState, int iRef) : m_iOldRef (0), m_pState(pState)
	{
		// Save the old "this" table
		lua_getglobal (m_pState, "this");
		// Creates and returns a reference, in the table at index t
		// for the object at the top of the stack (and pops the object).
		m_iOldRef = luaL_ref (m_pState, LUA_REGISTRYINDEX);

		// replace it with our new one
		lua_rawgeti(m_pState, LUA_REGISTRYINDEX, iRef);
		//Pops a value from the stack and sets it as the new value of global name. It is defined as a macro:
		lua_setglobal(m_pState, "this");
	}

	virtual ~CLuaThis (void)
	{
		if ( m_iOldRef > 0 && m_pState )
		{
			// Replace the old "this" table
			lua_rawgeti(m_pState, LUA_REGISTRYINDEX, m_iOldRef);
			// Pops a value from the stack and sets it as the new value of global name. It is defined as a macro:
			lua_setglobal (m_pState, "this");
			// Releases reference ref from the table at index t (see luaL_ref).
			// The entry is removed from the table, so that the referred object can be collected.
			// The reference ref is also freed to be used again.
			luaL_unref (m_pState, LUA_REGISTRYINDEX, m_iOldRef);
		}
	}

private:
	int m_iOldRef;
	lua_State* m_pState;
};

// script object
class CLuaScript
{
public:
	CLuaScript ();
	virtual ~CLuaScript ();

	// 初始化lua对象和脚本
	bool Init(lua_State* pState,const std::string & strLua);
	// 脚本重加载
	bool Reload();

	//szFmt: iils
	//	i : int
	//	f : double
	//	l : long		-- on 64bit platform, we cannot use type long in lua  -- by YQ
	//	s : string
	//	u : userdata (void *)
	//	e :	named obj ( name, obj )
	bool Call(const char* pszFunc, const char * szFmt, ...);

private:
	// Checks on Virtual Machine script
	bool HasFunction (const char *pszFunc);

private:
	lua_State* m_pState;
	int m_iThisRef;
	std::string m_strLuaName;
};



#endif /* LUASCRIPT_H_ */
