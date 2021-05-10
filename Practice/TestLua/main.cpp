// demo.cpp
#include <iostream>
// #include <gflags/gflags.h>
#include "gflags.h"
 #include "mylua.h"

using namespace std;

DEFINE_string(confPath, "../conf/setup.ini", "program configure file.");
DEFINE_int32(port, 9090, "program listen port");
DEFINE_bool(daemon, true, "run daemon mode");

DEFINE_string(name, "zhang san", "your name");
DEFINE_int32(age, 18, "your age");

int main(int argc, char** argv)
{
  gflags::ParseCommandLineFlags(&argc, &argv, true);
#if 0
  cout << "confPath = " << FLAGS_confPath << endl;
  cout << "port = " << FLAGS_port << endl;

  printf("\nthe name=%s, age=%d\n", FLAGS_name.data(), FLAGS_age);

  if (FLAGS_daemon) {
    cout << "run background ..." << endl;
  }
  else {
    cout << "run foreground ..." << endl;
  }

  cout << "good luck and good bye!" << endl;
#endif
  lua_State *L  = luaL_newstate();
  if(NULL == L)
  {
    printf("Create Lua State Error!\n");
    return -1;
  }
  int ret = luaL_dofile(L, "./Data/Data.lua");
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
