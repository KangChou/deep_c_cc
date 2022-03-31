cd same_cpp_A
# g++ mainA.cpp A.cpp #或 g++ mainA.cpp A.cpp A.h#
# include <>引入的文件，并不在当前目录搜索，只会在系统制定的目录搜索
g++ mainA.cpp A.cpp -I./  #-I可以将include <>原本的搜索目录进行扩展。
./a.out
cd ../


cd mono_cpp_A
# g++ mainA.cpp A/A.cpp
g++ mainA.cpp A/A.cpp -I.
./a.out
cd ../

cd mult_cpp_A
g++ mainA.cpp A/A.cpp A/C/C.cpp  -I. -I./A/
./a.out
cd ../


# 终端执行结果：bash run.sh 
# same_cpp_A ------->#include A() hahaa 888 测试成功！

# mono_cpp_A--------------->#include A() hahaa 888 测试成功！

# mult_cpp_A----------------->same_cpp_A#include A() hahaa 888 测试成功！

# 调用------->C()


#参考：https://blog.csdn.net/hl_java/article/details/90766721



