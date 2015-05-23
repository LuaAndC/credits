#include <lua.h>
#include <lauxlib.h>
#include <stdlib.h>

int removeGaps(lua_State* L) {
	luaL_argcheck(L, lua_type(L, 1) == LUA_TTABLE, 1, "Please, input table");

	size_t table_len = lua_objlen(L, -1);

	if (table_len == 0) {
		lua_newtable(L);
		return 1;
	}

	const char** table = malloc(sizeof(char*) * table_len);
	char** new_table = malloc(sizeof(char*) * table_len);

	size_t len;
	lua_rawgeti(L, 1, 1);
	table[0] = luaL_checklstring(L, -1, &len);
	luaL_argcheck(L, lua_type(L, -1) == LUA_TSTRING, -1, "Table members should be strings");
	lua_pop(L, 1);

	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; i < table_len; i++) {
		new_table[i] = malloc(sizeof(char) * len);
	}

	for (i = 2; i <= table_len; i++) {
		size_t local_len;
		lua_rawgeti(L, 1, i);
		table[i - 1] = luaL_checklstring(L, -1, &local_len);
		luaL_argcheck(L, local_len == len, -1, "Strings should have equal length");
		lua_pop(L, 1);
	}

	for (j = 0; j < len; j++) {
		char gap_column = "smth";
		for (i = 0; i < table_len; i++) {
			if (table[i][j] != '-') {
				gap_column = NULL;
			}
		}
		if (! gap_column) {
			for (i = 0; i < table_len; i++) {
				new_table[i][k] = table[i][j];
			}
			k = k + 1;
		}
	}

	lua_newtable(L);
	for (i = 0; i < table_len; i++) {
		lua_pushlstring(L, new_table[i], k);
		lua_rawseti(L, -2, i + 1);
	}

	for (i = 0; i < table_len; i++) {
		free(new_table[i]);
	}
	free(table);
	free(new_table);
	return 1;
}

int luaopen_gaps(lua_State* L) {
	lua_pushcfunction(L, removeGaps);
	return 1;
}
