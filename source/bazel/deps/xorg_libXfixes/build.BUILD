package(default_visibility = ["//visibility:public"])

hdrs = glob(
    include = [
        "include/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

cc_library(
    name = "hdrs",
    hdrs = hdrs,
    copts = [
    ],
    includes = [
        ".",
        "X11",
        "include",
        "include/X11",
        "include/X11/extensions",
        "src",
    ],
    deps = [
    ],
)

srcs = glob(
    include = [
        "src/**/*.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "xorg_libXfixes",
    srcs = srcs,
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        ".",
        "X11",
        "include",
        "include/X11",
        "include/X11/extensions",
        "src",
    ],
    deps = [
        ":hdrs",
        "@x11//:x11_hdrs",
        "@xorg_xorgproto",
    ],
)
