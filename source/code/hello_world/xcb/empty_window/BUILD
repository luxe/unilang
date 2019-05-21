load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    #copts = ["-L/usr/lib/x86_64-linux-gnu"],
    linkopts = ["-lxcb"],
    deps = [],
)


cc_binary(
    name = "main2",
    srcs = ["main2.cpp"],
    #copts = ["-L/usr/lib/x86_64-linux-gnu"],
    linkopts = ["-lxcb"],
    deps = [],
)

cc_binary(
    name = "event",
    srcs = ["event.cpp"],
    #copts = ["-L/usr/lib/x86_64-linux-gnu"],
    linkopts = ["-lxcb"],
    deps = [],
)
