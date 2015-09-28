/*
 * =====================================================================================
 *
 *       Filename:  lua.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/03/2014 05:32:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

int main(int argc, char *argv[])
{
	lua_State *L = lua_open();
	luaL_openlibs(L);
	luaL_dofile(L, "test.lua");
	lua_close(L);
	return 0;
}
