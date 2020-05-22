load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    copts = [
        "-DHAVE_CONFIG_H",
        "-DCAIRO_HAS_XLIB_SURFACE=1",  # Only effect is to create xlib display mutex
    ],
    linkopts = [
        "-lX11",
        "-lGL",
        "-lXext",
    ],
    deps = ["@cairo"],
)
