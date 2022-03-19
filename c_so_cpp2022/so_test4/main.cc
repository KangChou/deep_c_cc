#include <dlfcn.h>
#include <iostream>
typedef int (*inc_func)(int, int);
int main() {
  using namespace std;
  const char *so_name = "src/libadd.so";
  auto *dlhandle = dlopen(so_name, RTLD_LAZY);
  if (dlhandle == NULL) {
    cout << "ERROR open so";
    return -1;
  }
  dlerror();
  int a = 2, b = 3;
  inc_func inc = (inc_func)dlsym(dlhandle, "add");
  int res = inc(a, b);
  cout << a << "+" << b << " = " << res;
  dlclose(dlhandle);
  cout <<"\n"<< so_name << endl;
}
