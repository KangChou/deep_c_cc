#include <iostream>
#include "header.h"
using namespace std;


int main()
{
    int j = fact(5);
    cout << "5! is " << j << endl;
    for(int i=1; i<=5; ++i)
    {
        cout << static_val() << " ";
    }
    cout << endl;
    cout << "mabs(-8) is " << mabs(-8) << endl;
    return 0;
}