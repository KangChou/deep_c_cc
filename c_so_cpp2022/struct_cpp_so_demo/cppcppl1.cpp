//cppcppl1.cpp
#include <stdio.h>
#include <dlfcn.h>
using namespace std;
int main() {
	typedef int(*t_add)(int a, int b,int c);
	void *handle;
	handle = dlopen("./libcppl1.so", RTLD_LAZY);  //输入库
	t_add myadd = (t_add)dlsym(handle, "add");//导入库的函数参数或函数名
 
	int result = myadd(1, 2,200); //输入参数
 
	dlclose(handle);
 
	printf("%d\n", result);//输出结果
}