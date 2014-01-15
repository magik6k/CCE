#pragma once
extern  "C"
{
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
}


namespace term
{
    void init();
    int clear(lua_State *L);
    int setCursorPos(lua_State *L);
};
