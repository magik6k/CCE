#include "vm.h"
#include <iostream>
#include "eventPool.h"
#include "term.h"
using namespace std;

///void lua_setglobal (lua_State *L, const char *name);
///void lua_pushcfunction (lua_State *L, lua_CFunction f);
///int luaL_dofile (lua_State *L, const char *filename); (luaL_loadfile(L, filename) || lua_pcall(L, 0, LUA_MULTRET, 0))

int evt_handle(lua_State* L)
{
    event e = eventPool::getInstance().pool();
    for(unsigned int i = 0; i < e.len; ++i)
    {
        switch(e.data[i].type)
        {
            case et_boolean:
                lua_pushboolean(L, *(bool*)e.data[i].data);
                break;
            case et_integer:
                lua_pushinteger(L, *(int*)e.data[i].data);
                break;
            case et_number:
                lua_pushnumber(L, *(double*)e.data[i].data);
                break;
            case et_string:
                lua_pushstring(L, (*(string*)e.data[i].data).c_str());
                break;

        }
    }
    return e.len;
}

void vm::init_core_api()
{
    luaL_openlibs(this->L);

    lua_newtable(this->L); //CCE Internals
    lua_setglobal(this->L, "cce");
    lua_getglobal(this->L, "cce");

        lua_pushstring(this->L, "poolEvent");
        lua_pushcfunction(this->L, evt_handle);
        lua_settable(this->L, 1);

        lua_pushstring(this->L, "term");
        lua_newtable(this->L); //CCE Term

            lua_pushstring(this->L, "clear");
            lua_pushcfunction(this->L, term::clear);
            lua_settable(this->L, 3);

            lua_pushstring(this->L, "setCursorPos");
            lua_pushcfunction(this->L, term::setCursorPos);
            lua_settable(this->L, 3);

        lua_settable(this->L, 1);


}

void vm::start()
{
    this->L = luaL_newstate();
    this->init_core_api();

    luaL_dofile(this->L, "asset/bios");

}

vm::vm()
{
    this->start();

}

vm::~vm()
{
    lua_close(this->L);
}
