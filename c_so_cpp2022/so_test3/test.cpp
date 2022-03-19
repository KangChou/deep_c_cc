#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <iostream>
#include "add.h"
 
using namespace std;
 
int main(){
  int a = 0;
  a = add(3, 4);
  return 0;
}

