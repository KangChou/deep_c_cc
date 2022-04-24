bazel build //cc_a_library:static

bazel build //cc_so_library:libfunc.so

cd cc_a_library
mv libstatic.a ../call_so_a_library
cp static.h ../call_so_a_library

cd ../
cd cc_so_library
mv libfunc.so ../call_so_a_library
cp dllfunc.h ../call_so_a_library

cd ../
bazel build //call_so_a_library:dll_test