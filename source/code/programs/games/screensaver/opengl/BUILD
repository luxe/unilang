load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "//code/utilities/deps/external/gl:lib",
        "@system//:GLFW_hdrs",
        "@system//:X11",
        "@system//:X11_hdrs",
        "@system//:glfw",
        "@xscreensaver//:vroot",
    ],
)
