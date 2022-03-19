gcc -shared -fPIC -o libadd_c.so add.c
g++ test.cpp -L ./ ./libadd_c.so -ladd_c -o test 
export LD_PRELOAD="./libadd_c.so"
./test
