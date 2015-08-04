#include <lua.h>
#include <stdlib.h>
#include <lauxlib.h>

int TTT(lua_State* L) {
	luaL_argcheck(L, lua_type(L, 1) == LUA_TTABLE , 1, "Must table");
	int i = 0, j = 0;
	size_t len1, len2, len3;

	lua_rawgeti(L, 1, 1);
	lua_rawgeti(L, 1, 2);
	lua_rawgeti(L, 1, 3);

	if ((lua_type(L, 3) == LUA_TNIL)&& (lua_type(L, 4) == LUA_TNIL)&& (lua_type(L, 2) !=  LUA_TNIL)) {
		luaL_argcheck(L, lua_type(L, 2) == LUA_TSTRING , 2, "Must string");
		const char* str1 = luaL_checklstring(L, 2, &len1);
		char* charD1 = malloc(len1);
		for (i = 0; i < len1; i++) {
			if ((str1[i] == '-')) {
			
		} else {
			charD1[j] = str1[i];
			j = j + 1;
		}
		}
		for (i = j; i < len1; i++) {
				charD1[i] = ' ';
			}		
		lua_newtable(L);
		lua_pushlstring(L, charD1, j);
		lua_rawseti(L, 5, 1);
		free(charD1);

		
		
		} else if ((lua_type(L, 3) == LUA_TNIL)&& (lua_type(L, 4) == LUA_TNIL)&& (lua_type(L, 2) == LUA_TNIL)){
				lua_newtable(L);
			

		
		}  else if ((lua_type(L, 4) == LUA_TNIL)&& (lua_type(L, 2) != LUA_TNIL)&&(lua_type(L, 3) != LUA_TNIL)) {
		luaL_argcheck(L, lua_type(L, 2) == LUA_TSTRING , 2, "Must string");
		const char* str1 = luaL_checklstring(L, 2, &len1);		
		
		luaL_argcheck(L, lua_type(L, 2) == LUA_TSTRING , 3, "Must string");
		const char* str2 = luaL_checklstring(L, 3, &len2);
		luaL_argcheck(L, len1 == len2, 1, "Strings must be equal");
		char* charD1 = malloc(len1);
		char* charD2 = malloc(len1);
		
		
		for (i = 0; i < len1; i++) {
			if ((str1[i] == '-') && (str2[i] == '-')) {
			
		} else {
			charD1[j] = str1[i];
			charD2[j] = str2[i];
			j = j + 1;
		}
		}
		for (i = j; i < len1; i++) {
				charD1[i] = ' ';
				charD2[i] = ' ';

		}
		lua_newtable(L);
		lua_pushlstring(L, charD1, j);
		lua_rawseti(L, 5, 1);
		lua_pushlstring(L, charD2, j);
		lua_rawseti(L, 5, 2);
		
		free(charD1);
		free(charD2);
		
		
		
		} else {
		luaL_argcheck(L, lua_type(L, 2) == LUA_TSTRING , 2, "Must string");
		const char* str1 = luaL_checklstring(L, 2, &len1);	
		
		
		luaL_argcheck(L, lua_type(L, 3) == LUA_TSTRING , 3, "Must string");
		const char* str2 = luaL_checklstring(L, 3, &len2);
		luaL_argcheck(L, lua_type(L, 4) == LUA_TSTRING , 4, "Must string");		
		const char* str3 = luaL_checklstring(L, 4, &len3);
		luaL_argcheck(L, len1 == len2, 1, "Strings must be equal");
		luaL_argcheck(L, len2 == len3, 1, "Strings must be equal");
		char* charD1 = malloc(len1);
		char* charD2 = malloc(len1);
		char* charD3 = malloc(len1);
			for (i = 0; i < len1; i++) {
				if ((str1[i] == '-') && (str2[i] == '-') && (str3[i] == '-')) {
			
					} else {
						charD1[j] = str1[i];
						charD2[j] = str2[i];
						charD3[j] = str3[i];
						j = j + 1;
					}
			}
			for (i = j; i < len1; i++) {
				charD1[i] = ' ';
				charD2[i] = ' ';
				charD3[i] = ' ';
				}
		lua_newtable(L);
		lua_pushlstring(L, charD1, j);
		lua_rawseti(L, 5, 1);
		lua_pushlstring(L, charD2, j);
		lua_rawseti(L, 5, 2);
		lua_pushlstring(L, charD3, j);
		lua_rawseti(L, 5, 3);


		free(charD1);
		free(charD2);
		free(charD3);

		}
	
	return 1;
}

int luaopen_gaps(lua_State* L){
	lua_pushcfunction(L, &TTT);
	return 1;
}
