/*函数模板*/
#include<iostream>
#include<string>
using namespace std;

//template 关键字告诉C++编译器 下面是个泛型模板  
//数据类型T 参数化数据类型
template <typename T>
void generic_swap(T& a, T& b)
{
    cout << "Initial value: " << a << " : " << b << endl;

    T tmp;
    tmp = b;
    b = a;
    a = tmp;
}

int main()
{
    // 整形交换
    int a = 100, b = 50;
    generic_swap(a, b);
    cout << "excute the swap():" << a << " : " << b << endl;

    // 字符交换
    char c = 'A', d = 'B';
    generic_swap(c, d);
    cout << "excute the swap():" << c << " : " << d << endl;
    
    string e = "Jacky", f = "Lucy";
    generic_swap(e, f);
    cout << "excute the swap():" << e << " : " << f << endl;
    // 双精度交换
    double j = 1.314, k = 5.12;
    generic_swap(j, k);
    cout << "excute the swap():" << j << " : " << k << endl;
    
    return 0;
}