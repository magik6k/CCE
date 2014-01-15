#include "term.h"

namespace term
{
    void init()
    {
        printf ( "\033[2J\033[1;1H" );
    }
    int clear(lua_State *L)
    {
        printf ( "\033[2J" );
        return 0;
    }
    int setCursorPos(lua_State *L)
    {
        int i=0;
        printf("\033[%i;%iH",lua_tointeger(L, 1),lua_tointeger(L, 1));
        return 0;
    }
}
