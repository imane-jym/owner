/*
 * LuaState.h
 *
 *  Created on: 2011-7-8
 *      Author: yq
 */

#ifndef LUASTATE_H_
#define LUASTATE_H_

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

#include "Log.h"

struct lua_State;

class CLuaState
{
public:
	CLuaState ():m_pState(NULL) {};
	~CLuaState ()
	{
		Destroy();
	};

	bool Init()
	{
		Destroy();
		// Open Lua!
		m_pState = lua_open();
		if( NULL == m_pState )
		{
			IME_ERROR("lua_open failed");
			return false;
		}
		luaL_openlibs(m_pState);

		return true;
	};
	void Destroy()
	{
		if (m_pState)
		{
			lua_close (m_pState);
			m_pState = NULL;
		}
	};

	// Get the state of the lua stack (use the cast operator)
	lua_State* GetState() { return m_pState; };
private:
	lua_State *m_pState;
};


#endif /* LUASTATE_H_ */
