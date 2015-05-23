#include <lua.h>
#include <lauxlib.h>
#include <stdlib.h>
#if LUA_VERSION_NUM == 501
#define my_len lua_objlen
#else
#define my_len lua_rawlen
#endif

int removeGaps(char** table, char** new_table, int len_str, int len_table, int* new_sym_ind) {
    int sym_ind, str_ind;
    char gap_column;
    for (sym_ind = 0; sym_ind < len_str; sym_ind++) {
        gap_column = 't';
        for (str_ind = 0; str_ind < len_table; str_ind++) {
            if (table[str_ind][sym_ind] != '-') {
                gap_column = 'f';
            } 
        }
        if (gap_column == 'f') {
            *new_sym_ind = *new_sym_ind + 1;
            for (str_ind = 0; str_ind < len_table; str_ind++) {
                new_table[str_ind][*new_sym_ind] = table[str_ind][sym_ind];
            }
        } 
     }
     if (*new_sym_ind == -1) {
         return 0;
     } else {
         return 1;
     }
}

int wrapRemoveGaps(lua_State* L) {
    luaL_checktype(L, -1, LUA_TTABLE);
    char** table, **new_table;
    size_t len, len1;
    int len_table = my_len(L, -1);
    int str_ind, i;
    int new_sym_ind = -1;
    table = malloc(len_table * sizeof(char*));
    new_table = malloc(len_table * sizeof(char*));
    for (str_ind = 1; str_ind <= len_table; str_ind++) {
        lua_rawgeti(L, 1, str_ind);
        table[str_ind - 1] = luaL_checklstring(L, -1, &len1);
        if (str_ind == 1) {
            len = len1;
        }
        if (len != len1) {
            luaL_error(L, "fuck");
        }
    }
    for (i = 0; i < len_table; i++) {
        new_table[i] = malloc(len * sizeof(char));
    }
    int error = removeGaps(table, new_table, len, len_table, &new_sym_ind);
    //if (error != 1) {
      //  luaL_error(L, "fuck");
    //}
    lua_newtable(L); 
    for (str_ind = 0; str_ind < len_table; str_ind++) {
        lua_pushlstring(L, new_table[str_ind], new_sym_ind + 1);
        lua_rawseti(L, -2, str_ind + 1);
    }
    free(table);
    for (i = 0; i < len_table; i++) {
        free(new_table[i]);
    }
    free(new_table);
    return 1;
}
    
int luaopen_gaps(lua_State* L) {
    lua_pushcfunction(L, wrapRemoveGaps);
    return 1;
}
