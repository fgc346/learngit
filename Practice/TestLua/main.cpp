// demo.cpp
//此工程是c++与lua相互调用的例子示范
#include <iostream>
#include "gflags.h"
 #include "mylua.h"
 #include "common.h"

using namespace std;

DEFINE_string(confPath, "../conf/setup.ini", "program configure file.");
DEFINE_int32(port, 9090, "program listen port");
DEFINE_bool(daemon, true, "run daemon mode");

DEFINE_string(name, "zhang san", "your name");
DEFINE_int32(age, 18, "your age");

//c++调用lua
void cpp_call_lua() {
	// 初始化lua环境
	//lua_State *L = lua_open();  // lua5.1中使用luaL_newstate代替lua_open，lua_open不应该被直接调用
	lua_State *L = luaL_newstate();  
	if (L == NULL) {
		cout << "lua open failed !" << endl;
	}
	//luaopen_base(L);		// 打开lua基础库
	luaL_openlibs(L);		// 打开lua的io,string,math,table等高级库

	int ret = luaL_dofile(L, "./script/test.lua");
	if (ret) {
		cout << "lua dofile error !" << endl;
		return;
	}

	// 获取t[k]的值，k是字符串key
	lua_getglobal(L, "str");  // 根据name获取全局变量，并压入栈顶
	cout << "str is " << lua_tostring(L, -1) << endl;  // 读取全局变量

	lua_getglobal(L, "tab1");
	lua_getfield(L, -1, "k1");  // 根据index索引处的table变量获取key的值
	cout << "tab1.k1 is " << lua_tostring(L, -1) << endl;  // 将给定索引处的值转换为指定类型

	lua_getfield(L, -2, "k2");
	cout << "tab1.k2 is " << lua_tonumber(L, -1) << endl;

	// 获取t[index]的值，index是整型索引
	lua_getglobal(L, "tab2");
	lua_pushnumber(L, 4);  // 将一个数字压入栈顶
	lua_gettable(L, -2);   // 将t[k]压入栈顶，t是index索引处的表，k是栈顶的值
	cout << "tab2.4 is " << lua_tonumber(L, -1) << endl;

	// 调用函数
	lua_getglobal(L, "print_test");
	lua_call(L, 0, 0);  // 调用一个函数，参数2表示传递给lua函数的参数个数，参数3表示返回值的个数

	// 调用有参有返回值函数
	lua_getglobal(L, "add_sub");
	lua_pushnumber(L, 2);
	lua_pushnumber(L, 3);
	lua_call(L, 2, 2);
	if (lua_isnumber(L, -1)) {
		cout << "a - b is " << lua_tonumber(L, -1) << endl;
	}
	lua_pop(L, 1);  // 从栈中弹出n个元素
	cout << "a + b is " << lua_tonumber(L, -1) << endl;

	// 释放lua环境
	lua_close(L);
}


//lua调用c++
static int cpp_add_sub(lua_State *L) {
	int b = lua_tonumber(L, -1);  // 获取第二个参数
	int a = lua_tonumber(L, -2);  // 获取第一个参数
	lua_pushnumber(L, a + b);	// 压入第一个返回值
	lua_pushnumber(L, a - b);	// 压入第二个返回值
	return 2;  // 表示返回值的个数
}

void lua_call_cpp() {
	lua_State *L = luaL_newstate();
	if (L == NULL) {
		cout << "lua open failed !" << endl;
	}
	luaL_openlibs(L);		// 打开lua的io,string,math,table等高级库
	int ret = luaL_dofile(L, "./script/test.lua");
	if (ret) {
		cout << "lua dofile error !" << endl;
		return;
	}
	lua_register(L, "cpp_add_sub", cpp_add_sub);  // 将函数注册到lua的全局变量中

	lua_getglobal(L, "call_add_sub_from_cpp");  // 调用lua的call_add_sub_from_cpp函数，这个函数内部会调用C++函数
	lua_call(L, 0, 0);  
}

extern "C" int cpp_show_msg_box(lua_State *L) {
	cout << "print from cpp : cpp_show_msg_box" << endl;
	return 0;  // 返回值0个
}

//
// 导出函数列表
//
static luaL_Reg lua_libs[] = {
	{"cpp_show_msg_box", cpp_show_msg_box },
};

//
// dll入口函数，lua调用此dll的入口函数
// 当在lua中加载CppAndLuaCallTest.dll时，lua会根据此dll名字调用对应的函数 luaopen_dll名称
//
extern "C" 
int luaopen_CppAndLuaCallTest(lua_State* L) {
	luaL_register(L, "CppAndLuaCallTest", lua_libs);
//   lua_newtable(L);
//   luaL_setfuncs(L, lua_libs, 0);
	return 1;
}


//测试lua堆栈使用
void print_stacknum(const char *desc, const int count)
{
	printf("%s stack num = %d\n", desc, count);
}

static void stackDump(lua_State* L){
    cout<<"\nbegin dump lua stack"<<endl;
    int i = 0;
    int top = lua_gettop(L);
	// cout << "top = " << top << endl;
    for (i = 1; i <= top; ++i) {
        int t = lua_type(L, i);
        switch (t) {
            case LUA_TSTRING:
            {
                printf("'%s' ", lua_tostring(L, i));
				break;
            }

            case LUA_TBOOLEAN:
            {
                printf(lua_toboolean(L, i) ? "true " : "false ");
				break;
            }
            case LUA_TNUMBER:
            {
                printf("%g ", lua_tonumber(L, i));
				break;
            }
			// case LUA_TTABLE:
			// {
			// 	printf("'%s' ", lua_tostring(L,i));
			// 	break;
			// }
                
            default:
            {
                printf("%s ", lua_typename(L, t));
				break;
            }                
        }
    }
    cout<<"\nend dump lua stack"<<endl;
}

void test_api_getfield()
{
 	lua_State *L = lua_open();
	stackDump(L);

    luaL_dofile(L,"./script/fieldtest.lua");     // 加载执行lua文件
	stackDump(L);
    lua_getglobal(L,"param");           // 查找param变量压入栈底
	printf("\nlua_tostring(L,1)=%s\n", lua_tostring(L,2));
	stackDump(L);
	printf("lua_gettop(L)=%d\n", lua_gettop(L));
    print_stacknum("stage1", lua_gettop(L));

    lua_getfield(L, -1, "a");           // 将Param.a入栈
	stackDump(L);
    int nParam_a = lua_tointeger(L,-1); // 将Param.a取出赋值给变量nParam_a
	printf("nParam_a = %d\n", nParam_a);
	stackDump(L);
    lua_getfield(L, -2, "b");           // 将Param.b入栈
	stackDump(L);
    int nParam_b = lua_tointeger(L,-2); // 将Param.b取出赋值给变量nParam_b
	printf("nParam_b=%d\n", nParam_b);
    // print_stacknum("stage2",lua_gettop(L));

}

void test_api_getluavalue()
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	luaL_dofile(L,"./script/game.lua");
	//读取变量
	lua_getglobal(L,"name");
	printf("name = %s\n", lua_tostring(L, -1));
	//读取数字
	lua_getglobal(L,"age");
	printf("age=%g\n", lua_tonumber(L, -1));
	//读取表
	lua_getglobal(L,"player");
	//取表中元素
	lua_getfield(L, -1, "name");
	printf("player name = %s\n", lua_tostring(L, -1));
	lua_getfield(L, -2, "sex");
	printf("player sex = %s\n", lua_tostring(L, -1));

	//取函数
	lua_getglobal(L, "getCoin");
	lua_pushnumber(L,5);
	lua_pushnumber(L,3);
	lua_pcall(L,2,1,0);
	printf("5 + 3 = %g\n", lua_tonumber(L, -1));

	//关闭state
	lua_close(L);
}

//

void ParseLuaTable(lua_State *L, int i)
{
    if (!lua_istable(L, i))
    {
        return;
    }

    lua_pushnil(L);
    while (lua_next(L, -2))
    {
        fprintf(stdout, "%s : %s    ", luaL_typename(L,-2), luaL_typename(L,-1));
        int nKeyType = lua_type(L, -2);
        int nValueType = lua_type(L, -1);

        if (nKeyType == LUA_TNUMBER)
        {
            fprintf(stdout, "%g,", lua_tonumber(L, -2));
        }
        else if (nKeyType == LUA_TSTRING)
        {
            fprintf(stdout, "\"%s\",", lua_tostring(L, -2));
        }
        fprintf(stdout, "   ");  
        if (nValueType == LUA_TNUMBER)
        {
            fprintf(stdout, "%g", lua_tonumber(L, -1));
        }
        else if (nValueType == LUA_TSTRING)
        {
            fprintf(stdout, "\"%s\"", lua_tostring(L, -1));
        }
        else if (nValueType == LUA_TTABLE)
        {
            fprintf(stdout, "\n");
            ParseLuaTable(L, i);
        }   

        lua_pop(L, 1);
        fprintf(stdout, "\n");   
    }
}


void lua_GetMetaData()
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	luaL_dofile(L,"./script/case.lua");
	lua_getglobal(L, "GetMetaData");
	//lua_pcall来调用栈中的函数，捕获所有错误。而在为Lua编写扩展的C函数时，应该调用lua_call，把错误返回到脚本层
	lua_pcall(L,0, 4,0);
	//stackDump打印虚拟堆栈信息
	// stackDump(L);
	printf("L,size = %d\n", lua_gettop(L));
	int num = lua_gettop(L);
	for (int i = 1; i <=  num; i++)
	{
		printf("after pop table, the top = %d\n", lua_gettop(L));
		if(lua_isnumber(L, lua_gettop(L)))
		{
			printf("index %d is  number = %d\n", i, (int)lua_tonumber(L, -1));
		}
		else if(lua_isstring(L, lua_gettop(L)))
		{
			printf("index %d is  string = %s\n", i, lua_tostring(L, -1));
		}
		else if(lua_istable(L, lua_gettop(L)))
		{
			printf("index %d is table\n", i);
			ParseLuaTable(L, -1);
		}
		else
		{
			printf("index %d is %s\n", i, lua_typename(L, -1));
		}	
		lua_pop(L,1);		//从栈顶弹出一个元素
	}
	
	lua_close(L);
	return;
	
#if 0
	lua_pushnil(L);
	// lua_gettable(L, -2);
	while(lua_next(L, -2))
	{
		std::string strkey = lua_tostring(L, -2);
		std::string strValue = lua_tostring(L, -1);
		printf("key = %s, value = %s\n", strkey.data(), strValue.data());
		lua_pop(L, 1);
	}
#endif

	
}



int main(int argc, char** argv)
{
	lua_GetMetaData();
	// test_api_getluavalue();
	// test_api_getfield();

	// test1();
  // cpp_call_lua();
//   lua_call_cpp();
  return 0;


  gflags::ParseCommandLineFlags(&argc, &argv, true);
  lua_State *L  = luaL_newstate();
  if(NULL == L)
  {
    printf("Create Lua State Error!\n");
    return -1;
  }
  int ret = luaL_dofile(L, "./script/Data.lua");
  if(ret)
  {
    printf("Lua doFile Error!\n");
    return -2; 
  }

  lua_getglobal(L, "Data");
  lua_pushstring(L, "name");
  lua_gettable(L, -2);
  if(lua_isstring(L, -1))
  {
    std::string str = lua_tostring(L, -1);
    printf("str = %s\n",str.data());
  }
  lua_close(L);
  gflags::ShutDownCommandLineFlags();
  return 0;
}
