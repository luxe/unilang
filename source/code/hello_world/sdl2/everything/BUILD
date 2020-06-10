load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    copts = ["-pthread"],
    linkopts = [
        "-pthread",
        "-lpthread",
        "-lrt",
    ],
    deps = ["@sdl2"],
)
