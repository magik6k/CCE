#pragma once
extern  "C"
{
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
}

class vm
{
    private:
        lua_State *L;
        lua_State *main;

        void init_core_api();
        void start();

    public:

        vm();
        ~vm();

};
