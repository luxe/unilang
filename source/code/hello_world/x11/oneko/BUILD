load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    copts = [
        "-Wno-everything",
    ],
    deps = [
        "//code/hello_world/x11/oneko/bitmaps/bsd:lib",
        "//code/hello_world/x11/oneko/bitmaps/dog:lib",
        "//code/hello_world/x11/oneko/bitmaps/neko:lib",
        "//code/hello_world/x11/oneko/bitmaps/sakura:lib",
        "//code/hello_world/x11/oneko/bitmaps/tomoyo:lib",
        "//code/hello_world/x11/oneko/bitmaps/tora:lib",
        "//code/hello_world/x11/oneko/bitmasks/bsd:lib",
        "//code/hello_world/x11/oneko/bitmasks/dog:lib",
        "//code/hello_world/x11/oneko/bitmasks/neko:lib",
        "//code/hello_world/x11/oneko/bitmasks/sakura:lib",
        "//code/hello_world/x11/oneko/bitmasks/tomoyo:lib",
        "//code/hello_world/x11/oneko/cursors:lib",
        "@x11",
    ],
)
