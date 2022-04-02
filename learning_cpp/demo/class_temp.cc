/*类模板*/
#include<iostream>
#include<string>
using namespace std;

//注意：模板头和类头是一个整体，可以换行，但是中间不能有分号
template<typename T1, typename T2>  //这里不能有分号
class Point {
public:
    Point(T1 x, T2 y) : m_x(x), m_y(y) { }
public:
    T1 getX() const;  //获取x坐标
    void setX(T1 x);  //设置x坐标
    T2 getY() const;  //获取y坐标
    void setY(T2 y);  //设置y坐标
private:
    T1 m_x;  //x坐标
    T2 m_y;  //y坐标
};

//下面就对 Point 类的成员函数进行定义
template<typename T1, typename T2> T1 Point<T1, T2>::getX() const {
    return m_x;
}

template<typename T1, typename T2> void Point<T1, T2>::setX(T1 x) {
    m_x = x;
}

template<typename T1, typename T2> T2 Point<T1, T2>::getY() const {
    return m_y;
}

template<typename T1, typename T2> void Point<T1, T2>::setY(T2 y) {
    m_y = y;
}

int main()
{
    // 与函数模板不同的是，类模板在实例化时必须显式地指明数据类型
    // 编译器不能根据给定的数据推演出数据类型
    Point<int, int> p1(10, 10);
    cout << "x=" << p1.getX() << ", y=" << p1.getY() << endl;

    Point<float, float> p2(12.88, 129.65);
    cout << "x=" << p2.getX() << ", y=" << p2.getY() << endl;

    Point<string, string> p3("E180","N210");
    cout << "x=" << p3.getX() << ", y=" << p3.getY() << endl;

    Point<int, float> p4(4, 129.65);
    cout << "x=" << p4.getX() << ", y=" << p4.getY() << endl;

    Point<string, int> p5("hello,world!", 5);
    cout << "x=" << p5.getX() << ", y=" << p5.getY() << endl;

    //除了对象变量，我们也可以使用对象指针的方式来实例化
    Point<string, int>* p7 = new Point<string, int>("hello,world!", 7);
    // (pointer_name)->(variable_name)
    // The Dot(.) operator is used to normally access members of a structure or union.
    // The Arrow(->) operator exists to access the members of the structure or the unions using pointers
    cout << "x=" << p7->getX() << ", y=" << p7->getY() << endl;
    
    delete p7;

    return 0;
}