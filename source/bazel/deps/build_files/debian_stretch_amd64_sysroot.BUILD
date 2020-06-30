package(default_visibility = ["//visibility:public"])

filegroup(
    name = "sysroot",
    srcs = glob(["*/**"]),
)

cc_import(
    name = "GL",
    shared_library = "usr/lib/x86_64-linux-gnu/libGL.so",
    #alwayslink=0,
)
