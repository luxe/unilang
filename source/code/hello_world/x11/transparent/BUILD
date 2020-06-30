load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        "@debian_stretch_amd64_sysroot//:GL",
        "@glut",
        "@mesa",
        "@x11",
    ],
)
