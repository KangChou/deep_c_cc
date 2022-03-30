//cppl1.cpp
// #include <iostream>
// #include <string>
// using namespace std;

struct result
{
	int x;
	int y;
};
 
result * fun()
{
	result *test=new result;
	test->x=100;
	test->y=458;

	return test;
}

extern "C" int add(int a, int b,int c) 
{
	result *test;
	test=fun();
	a = a + test->x;
	b = b + test->y;

	return a+b+c*2;
}

