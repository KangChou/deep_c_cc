#include "A.h" 
// #include <A.h> //这个报错   //因此选择：g++ mainA.cpp A.cpp -I./
//include <>引入的文件，并不在当前目录搜索，只会在系统制定的目录搜索
int main()
{
    A a;
    
    return 0;
}