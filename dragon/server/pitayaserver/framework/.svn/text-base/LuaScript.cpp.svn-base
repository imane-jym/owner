/*
 * LuaScript.cpp
 *
 *  Created on: 2011-7-8
 *      Author: yq
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>
#include <lua5.1/lualib.h>

#ifdef __cplusplus
}
#endif

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Log.h"
#include "LuaScript.h"
#include <assert.h>
#include <tolua++.h>

CLuaScript::CLuaScript ()
 : m_pState(NULL), m_iThisRef (0)
{
}

CLuaScript::~CLuaScript ()
{
	if( m_pState )
	{
		CLuaRestoreStack rs(m_pState);
		luaL_unref(m_pState, LUA_REGISTRYINDEX, m_iThisRef);
		m_iThisRef = 0;
		m_pState = NULL;
	}
}

bool CLuaScript::Init(lua_State* pState,const std::string & strLua)
{
	if( !pState )
	{
		IME_ERROR("pState is NULL");
		return false;
	}
	if( strLua.size() == 0 )
	{
		IME_ERROR("strLua is NULL");
		return false;
	}
	m_pState = pState;
	// Create a reference to the "this" table. Each reference is unique
	lua_newtable (m_pState);
	m_iThisRef = luaL_ref (m_pState, LUA_REGISTRYINDEX);

	// Save the "this" table to index 0 of the "this" table
	CLuaRestoreStack rs(m_pState);
	lua_rawgeti (m_pState, LUA_REGISTRYINDEX, m_iThisRef);
	lua_pushlightuserdata (m_pState, (void *) this);
	lua_rawseti (m_pState, -2, 0);

	m_strLuaName = strLua;

	return Reload();
}

bool CLuaScript::Reload()
{
	// m_strLuaName can not be null
	if( m_strLuaName.size() == 0 )
	{
		IME_ERROR("script name is NULL");
		return false;
	}
	if( NULL == m_pState )
	{
		IME_ERROR("lua_state not init");
		return false;
	}
	// Make sure we have the correct "this" table
	CLuaThis luaThis(m_pState, m_iThisRef);
	int nRet = luaL_loadfile(m_pState, m_strLuaName.c_str());
	if( nRet != 0 )
	{
		IME_ERROR("luaL_loadfile failed %d-%s",nRet,lua_tostring(m_pState,-1));
		return false;
	}
	nRet = lua_pcall(m_pState,0,LUA_MULTRET,0);
	if( nRet != 0 )
	{
		IME_ERROR("lua_pcall failed %d-%s",nRet,lua_tostring(m_pState,-1));
		return false;
	}
	return true;
}

bool CLuaScript::HasFunction (const char *pszFunc)
{
	if( !m_pState )
	{
		IME_ERROR("virtual machine not init yet","");
		return false;
	}
	if( NULL == pszFunc || strlen(pszFunc) == 0 )
	{
		IME_ERROR("function name illegal","");
		return false;
	}
	CLuaRestoreStack rs(m_pState);

	lua_rawgeti(m_pState, LUA_REGISTRYINDEX, m_iThisRef);
	lua_pushstring(m_pState, pszFunc);
	lua_rawget(m_pState, -2);
	lua_remove(m_pState, -2);
	if ( !lua_isfunction(m_pState, -1) )
	{
		IME_ERROR("function name invalid : %s",pszFunc);
		return false;
	}
	return true;
}


bool CLuaScript::Call(const char * pszFunc, const char * szFmt, ...)
{
	if( !HasFunction(pszFunc) )
	{
		IME_ERROR("Call Function Failed","");
		return false;
	}

	CLuaRestoreStack rs(m_pState);

	// Look up function name
	lua_rawgeti (m_pState, LUA_REGISTRYINDEX, m_iThisRef);
	lua_pushstring (m_pState, pszFunc);
	lua_rawget (m_pState, -2);
	lua_remove (m_pState, -2);
	// Put the "this" table back
	lua_rawgeti (m_pState, LUA_REGISTRYINDEX, m_iThisRef);
	int nArgc = 0;

	va_list arg_ptr;
	va_start(arg_ptr,szFmt);

	int nReturns = 0;
	int nLen = strlen( szFmt );
	for ( int i=0; i<nLen; i++ )
	{
		switch( szFmt[i] )
		{
			case 'l':
			{
				long value = va_arg(arg_ptr,long);
				lua_pushnumber(m_pState, value);
				break;
			}
			case 's':
			{
				const char * str = va_arg(arg_ptr, const char*);
				lua_pushstring(m_pState, str);
				break;

			}
			case 'u':
			{
				void * p = va_arg(arg_ptr, void*);
				lua_pushlightuserdata(m_pState, p);
				break;

			}
			case 'i':
			{
				int value = va_arg(arg_ptr, int);
				lua_pushnumber(m_pState, value);
				break;
			}
			case 'f':
			{
				double value = va_arg(arg_ptr, double);

				lua_pushnumber(m_pState,value);
				break;
			}
			case 'e':
			{
				const char* pszName = va_arg( arg_ptr, const char* );
				void* pObj = va_arg( arg_ptr, void* );
				tolua_pushusertype( m_pState, pObj, pszName );
				nReturns = 1;
				break;
			}
			default:
			{
				IME_ERROR("param undefined:%c", szFmt[i] );
				assert( false );
			}
		}
		++nArgc;
	}

	int nRet = lua_pcall(m_pState,nArgc+1,nReturns,0);
	if( nRet != 0 )
	{
		IME_ERROR("lua_pcall failed %d-%s",nRet,lua_tostring(m_pState,-1));
		return false;
	}
	return true;
}
