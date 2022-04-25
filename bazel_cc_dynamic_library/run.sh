bazel build //cc_a_library:static

bazel build //cc_so_library:libfunc.so
# 
chmod 777 -R bazel-*

cd bazel-out/k8-fastbuild/bin/cc_a_library
cd ../../../../
cp bazel-out/k8-fastbuild/bin/cc_a_library/libstatic.a call_so_a_library
cp cc_a_library/static.h call_so_a_library

pwd

cd bazel-out/k8-fastbuild/bin/cc_so_library
cd ../../../../
cp bazel-out/k8-fastbuild/bin/cc_so_library/libfunc.so call_so_a_library
cp cc_so_library/dllfunc.h call_so_a_library


bazel build //call_so_a_library:dll_test
bazel run //call_so_a_library:dll_test


rm -rf bazel-*
rm call_so_a_library/libfunc.so
rm call_so_a_library/libstatic.a
