//readTF.cpp
// #include "/opt/conda/pkgs/python-3.6.8-h0371630_0/include/python3.6m/Python.h"
// #include "/opt/conda/pkgs/python-3.6.8-h0371630_0/include/python3.6m/pythonrun.h"
#include "/usr/include/python2.7/Python.h"
#include "/usr/include/python2.7/pythonrun.h"
#include <iostream>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

int main()
{
  const int flag= 1;
  Py_Initialize();
  if (!Py_IsInitialized())
  {
    return -1;
  }

  PyRun_SimpleString("import sys");
  //路径一定要对
  PyRun_SimpleString("sys.path.append('/data/Documents/tensorfow_py_so_cpp_2022/')");
  
  PyObject* pMod = NULL;
  PyObject* pFunc = NULL;
  PyObject* pParm = NULL;
  PyObject* pRetVal = NULL;
  int iRetVal=999;
  PyObject* pName = PyString_FromString("classify");
  pMod = PyImport_Import(pName);//获取模块
  if (!pMod)
  {
	std::cout << pMod <<std::endl;
    return -1;
  }
  const char* funcName = "evaluate";
  pFunc = PyObject_GetAttrString(pMod,funcName);//获取函数
  if (!pFunc)
  {
    std::cout << "pFunc error" <<std::endl;
    return -1;
  }
  
  pParm = PyTuple_New(1);//新建元组
  PyTuple_SetItem(pParm, 0, Py_BuildValue("i",flag));//向Python模块传参
  pRetVal = PyObject_CallObject(pFunc,pParm);//获得返回结果

  PyArg_Parse(pRetVal,"i",&iRetVal);//解析成C++需要的形式
  std::cout<< iRetVal <<std::endl;
  return 0;
}
