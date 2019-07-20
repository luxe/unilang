load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = ["-lX11", "-lXext", "-lXpm"],
    copts = [
        "-Wno-everything",
    ],
    deps = [
        "//code/utilities/x11/main_state:x11_main_state_creator",
        "//code/utilities/x11/sprite:sprite_loader",
        "//code/utilities/x11/sprite:sprite_window_creator",
        "//code/utilities/x11/sprite:sprite_window_drawer",
        "//code/utilities/x11/loop:x11_looper",
    ]
)