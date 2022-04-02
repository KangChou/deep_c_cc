echo "---------------函数模板------------------"

g++ fun_temp.cc -o fun_temp && ./fun_temp

echo "---------------类模板------------------"

g++ class_temp.cc -o class_temp && ./class_temp
rm ./fun_temp
rm ./class_temp

echo "---------------完成测试------------------"