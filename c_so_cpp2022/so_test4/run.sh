rm -rf build
mkdir build 
cd build
cmake .. 
make && ./DLDEMO

# g++ src/add.cc -fPIC -shared -Iinclude -o src/libadd.so # 编译生成动态库
# g++ main.cc -ldl -o DLDEMO && ./DLDEMO