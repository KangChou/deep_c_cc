gcc -shared -fpic -lm -ldl -o libadd_c.so add.c && g++ test.cpp -ldl -o test && ./test
