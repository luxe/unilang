load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
        "-lGLU",
        "-lglut",
    ],
    deps = [
        "@GL",
        "@GLU_so//:lib",
        "@glut_so//:lib",
        "@glut",
        "@x11",
        "@mesa",
    ],
)
