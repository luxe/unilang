package(default_visibility = ["//visibility:public"])

cc_library(
    name = "headers",
    hdrs = [
        "src/config.h",
        "src/xinput.h",
    ],
    includes = [
        ".",
        "src/",
    ],
)

cc_library(
    name = "lib",
    srcs = glob(
        ["src/**/*.c"],
        exclude = ["src/xinput.c"],
    ),
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        ".",
        "src/",
    ],
    linkopts = [
    ],
    deps = [
        ":headers",
        "@x11//:x11_hdrs",
        "@xorg_libXext",
        "@xorg_libXi",
        "@xorg_libXinerama",
        "@xorg_libXrandr",
        "@xorg_xorgproto",
    ],
)

cc_binary(
    name = "xinput",
    srcs = ["src/xinput.c"],
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        ".",
        "src/",
    ],
    deps = [
        ":lib",
    ],
)
