#include <lua.h>
#include <lauxlib.h>

int distance(lua_State* L) {
    size_t len1, len2;
    const char* str1 = luaL_checklstring(L, 1, &len1);
    const char* str2 = luaL_checklstring(L, 2, &len2);
    luaL_argcheck(L, len1 == len2, 2,
            "Expect strings of equal length");
    char* result = lua_newuserdata(L, len1);
    int mismatches = 0;
    int i;
    for (i = 0; i < len1; i++) {
        char a = str1[i];
        char b = str2[i];
        luaL_argcheck(L, a == '0' || a == '1', 1,
                "Only characters '0' and '1' are allowed");
        luaL_argcheck(L, b == '0' || b == '1', 1,
                "Only characters '0' and '1' are allowed");
        if (a == b) {
            result[i] = a;
        } else {
            if (mismatches % 2 == 0) {
                result[i] = a;
            } else {
                result[i] = b;
            }
            mismatches += 1;
        }
    }
    if (mismatches % 2 == 1) {
        // result = impossible
        lua_pushnil(L);
        return 1;
    }
    lua_pushlstring(L, result, len1);
    return 1;
}

int luaopen_distance(lua_State* L) {
    lua_pushcfunction(L, distance);
    return 1;
}
