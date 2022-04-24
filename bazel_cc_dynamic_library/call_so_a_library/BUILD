cc_import(
        name="dllfunc",
        hdrs=["dllfunc.h"],
        shared_library="libfunc.so",
        )

cc_import(
        name="staticfunc",
        hdrs=["static.h"],
        static_library="libstatic.a",
        )
cc_binary(
        name="dll_test",
        srcs=["main.cc"],
        deps=[":dllfunc",":staticfunc"],
        )



