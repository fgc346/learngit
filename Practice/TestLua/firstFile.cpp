#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include<iostream>

extern "C" int luaopen_firstLib(lua_State *L);
int InternalHello(lua_State* L) {
    std::cout<<"Hello World!"<<std::endl;
    return 0;
}
int luaopen_firstLib(lua_State *L){
    static const luaL_Reg Map[]={
        {"look",InternalHello},
        {NULL,NULL}         //数组中最后一对必须是{NULL, NULL}，用来表示结束   
    };  
    luaL_register(L,"first",Map);        //5.3已经不支持了,5.1的语法
    // lua_newtable(L);
    // luaL_setfuncs(L, Map, 0);
    return 1;                       // 把myLib表压入了栈中，所以就需要返回1 
}