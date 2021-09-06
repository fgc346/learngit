/*
 * @Author: fenggaochao
 * @Date: 2021-09-06 14:49:35
 * @LastEditTime: 2021-09-06 16:32:26
 * @LastEditors: fenggaochao
 * @Description: 
 * @FilePath: /CPlusPlusCallPython/main.cpp
 */
#include <Python.h>
#include <iostream>
#include <string>
using namespace std;  
  
void HelloWorld();  
void Add();  
void TestTransferDict();  
void TestClass();  
void TestPython();

int main () {
	printf("hello,world\n");
	TestPython();

	cout << "HelloWorld()-------------" << endl;  
	HelloWorld();  
	cout << "Add()--------------------" << endl;  
	Add();  
	cout << "TestDict-----------------" << endl;  
	TestTransferDict();  
	cout << "TestClass----------------" << endl;  
	TestClass();  
	//使用python之前，要调用Py_Initialize();这个函数进行初始化
	Py_Initialize();
	//导入环境变量
	PyRun_SimpleString("import sys");
	//python脚本路径
	PyRun_SimpleString("sys.path.append('./script')"); //放在script路径下

	PyObject * pModule = NULL;
	PyObject * pFunc = NULL;
	PyObject * pClass = NULL;
	PyObject * pInstance = NULL;


	// pModule = PyImport_ImportModule("myhello");

	// Py_DECREF (pModule);

	// //这里是要调用的函数名
	// pFunc= PyObject_GetAttrString(pModule, "hello");
	// //调用函数
	// PyEval_CallObject(pFunc, NULL);
	// Py_DECREF(pFunc);

	//测试调用python的类
	// pClass = PyObject_GetAttrString(pModule, "Student");
	// if (!pClass) {
	// 	printf("Can't find Student class.\n");
	// 	return -1;
	// }
	// pInstance = PyInstanceMethod_New(pClass);
	// if (!pInstance) {
	// 	printf("Can't create Student instance.\n");
	// 	return -1;
	// }
	// PyObject* pIns = PyObject_CallObject(pInstance,nullptr);

	//调用其中的类方法
	// PyObject_CallMethod(pIns, "SetName", "(s)", "I am C++ args");
	// PyObject_CallMethod(pIns, "PrintName", nullptr);
	//调用Py_Finalize，这个根Py_Initialize相对应的。
	Py_Finalize();
	return 0;
}



void TestPython() {
	Py_Initialize();
	if(!Py_IsInitialized())
	{
			std::cout <<"1" <<std::endl;
	}
	PyRun_SimpleString("import sys");
	int argc = 1;
	PyRun_SimpleString("sys.path.append('./script')");

	if(PyRun_SimpleString("exec(open('./script/my_test.py').read())") == nullptr)
	{
			std::cout <<"PyRun_SimpleString is execute" <<std::endl;
	}
	Py_Finalize();
}

//调用输出"Hello World"函数  
void HelloWorld()  
{  
    Py_Initialize();              //使用python之前，要调用Py_Initialize();这个函数进行初始化
		//导入环境变量
		PyRun_SimpleString("import sys");
		//python脚本路径
		PyRun_SimpleString("sys.path.append('./script')"); //放在script路径下  
    PyObject * pModule = NULL;    //声明变量  
    PyObject * pFunc = NULL;      //声明变量  
    pModule =PyImport_ImportModule("Test001");              //这里是要调用的Python文件名  
    pFunc= PyObject_GetAttrString(pModule, "HelloWorld");   //这里是要调用的函数名  
    PyEval_CallObject(pFunc, NULL);                         //调用函数,NULL表示参数为空  
    Py_Finalize();                //调用Py_Finalize,这个和Py_Initialize相对应的.  
}  
  
//调用Add函数,传两个int型参数  
void Add()  
{  
    Py_Initialize();
		//导入环境变量
		PyRun_SimpleString("import sys");
		//python脚本路径
		PyRun_SimpleString("sys.path.append('./script')"); //放在script路径下    
  
    PyObject * pModule = NULL;      
    PyObject * pFunc = NULL;        
    pModule =PyImport_ImportModule("Test001");      //Test001:Python文件名
		//python脚本路径
    pFunc= PyObject_GetAttrString(pModule, "add");  //Add:Python文件中的函数名  
		//创建参数:  
    PyObject *pArgs = PyTuple_New(2);               //函数调用的参数传递均是以元组的形式打包的,2表示参数个数  
    PyTuple_SetItem(pArgs, 0, Py_BuildValue("i", 5));//0---序号  i表示创建int型变量  
    PyTuple_SetItem(pArgs, 1, Py_BuildValue("i", 7));//1---序号  
		//返回值  
    PyObject *pReturn = NULL;  
    pReturn = PyEval_CallObject(pFunc, pArgs);      //调用函数  
		//将返回值转换为int类型  
    int result;  
    PyArg_Parse(pReturn, "i", &result);    //i表示转换成int型变量  
    cout << "5+7 = " << result << endl;  
  
    Py_Finalize();                  
}  
  
//参数传递的类型为字典  
void TestTransferDict()  
{  
    Py_Initialize();  
 		//导入环境变量
		PyRun_SimpleString("import sys");
		//python脚本路径
		PyRun_SimpleString("sys.path.append('./script')"); //放在script路径下    
    PyObject * pModule = NULL;      
    PyObject * pFunc = NULL;        
    pModule =PyImport_ImportModule("Test001");      //Test001:Python文件名
		//python脚本路径
    pFunc= PyObject_GetAttrString(pModule, "TestDict"); //Add:Python文件中的函数名  
		//创建参数:  
    PyObject *pArgs = PyTuple_New(1);   
    PyObject *pDict = PyDict_New();   //创建字典类型变量  
    PyDict_SetItemString(pDict, "Name", Py_BuildValue("s", "WangYao")); //往字典类型变量中填充数据  
    PyDict_SetItemString(pDict, "Age", Py_BuildValue("i", 25));         //往字典类型变量中填充数据  
    PyTuple_SetItem(pArgs, 0, pDict);//0---序号  将字典类型变量添加到参数元组中  
		//返回值  
    PyObject *pReturn = NULL;  
    pReturn = PyEval_CallObject(pFunc, pArgs);      //调用函数  
		//处理返回值:  
    int size = PyDict_Size(pReturn);  
    cout << "返回字典的大小为: " << size << endl;  
    PyObject *pNewAge = PyDict_GetItemString(pReturn, "Age");  
    int newAge;  
    PyArg_Parse(pNewAge, "i", &newAge);  
    cout << "True Age: " << newAge << endl;  
      
    Py_Finalize();                  
}  
  
//测试类  
void TestClass()  
{  
    Py_Initialize();  
 		//导入环境变量
		PyRun_SimpleString("import sys");
		//python脚本路径
		PyRun_SimpleString("sys.path.append('./script')"); //放在script路径下    
    PyObject * pModule = NULL;      
    PyObject * pFunc = NULL;        
    pModule =PyImport_ImportModule("Test001");      //Test001:Python文件名
		//python脚本路径
    pFunc= PyObject_GetAttrString(pModule, "TestDict"); //Add:Python文件中的函数名  
		//获取Person类  
    PyObject *pClassPerson = PyObject_GetAttrString(pModule, "Person");  
    //创建Person类的实例  
    PyObject *pInstancePerson = PyInstanceMethod_New(pClassPerson);  
    //调用方法  
    PyObject_CallMethod(pInstancePerson, "greet", "s", "Hello Kitty");   //s表示传递的是字符串,值为"Hello Kitty"  
  
    Py_Finalize();            
}