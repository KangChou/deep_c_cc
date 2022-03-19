#include <stdio.h>
#include <dlfcn.h>

int main()
{
    /*手动加载指定位置的so动态库*/
    void* handle = dlopen("./libadd.so", RTLD_LAZY);
    int (*add)(int a, int b);

    /*根据动态链接库操作句柄与符号，返回符号对应的地址*/
    add = dlsym(handle, "add");

    int sum = add(7, 8);
    printf("7+8 = %d\n", sum);

    dlclose(handle);
    return 0;
}