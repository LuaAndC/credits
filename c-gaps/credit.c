#include <lua.h>
#include <lauxlib.h>

#include <stdlib.h>


int clear_gaps(lua_State* L)
{
	luaL_argcheck(L, lua_istable(L, -1), -1, "Error, table_required\n");
	
	size_t table_len = lua_objlen(L, -1);
	
	if ( table_len == 0)
	{
		lua_newtable(L);
		return 1;
	}

	const char** in_table = (const char**)malloc(sizeof(char*) * table_len);

	// get first string
	size_t f_size;
	lua_rawgeti(L, 1, 1);
	in_table[0] = luaL_checklstring(L, -1, &f_size);
	lua_pop(L, 1);

	//lua_istable
	
	int i = 2;
	for (; i <= table_len; i++)
	{
		size_t str_size;
		lua_rawgeti(L, 1, i);

		in_table[i - 1] = luaL_checklstring(L, -1, &str_size);
		lua_pop(L, 1);

		luaL_argcheck(L, str_size == f_size, -1, "Error, sequences must have the same length\n");
	}

	// create place for out table
	char** out_table = (char**)malloc(sizeof(char*) * table_len);
	for (i = 0; i < table_len; i++)
	{
		out_table[i] = (char*)malloc(sizeof(char) * f_size);
	}

	int j = 0;
	size_t new_size = 0;

	// delete only gaps columns
	for (; j < f_size; j++)
	{
		char only_gaps = 1;
		for (i = 0; i < table_len; i++)
		{
			if (in_table[i][j] != '-')
			{
				only_gaps = 0;
			}
		}


		if (! only_gaps) 
		{
			for (i = 0; i < table_len; i++)
			{
				out_table[i][new_size] = in_table[i][j];
			}
			new_size++;
		}
	}

	
	lua_newtable(L); // create lua table

	for (i = 0; i < table_len; i++)
	{
		lua_pushlstring(L, out_table[i], new_size);
		lua_rawseti(L, -2, i + 1);
	}

	// free memory
	
	for (i = 0; i < table_len; i++)
	{
		free(out_table[i]);
	}
	free(in_table);
	free(out_table);
	return 1; // function returns one argument
}

int luaopen_gaps(lua_State* L) {
    // return it here
    return 0;
}
