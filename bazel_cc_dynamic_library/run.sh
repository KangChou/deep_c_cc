bazel build //cc_a_library:static

bazel build //cc_so_library:dllfunc-0.0.1.so

cd cc_a_library
mv libstatic.a ../call_so_a_library

cd ../
cd cc_so_library
mv libstatic.so ../call_so_a_library
cd ../
bazel build //call_so_a_library:dll_test