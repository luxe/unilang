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
    name = "libXpm_headers",
    hdrs = hdrs,
    copts = [
    ],
    includes = [
        "include",
        "include/X11",
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
        "src/amigax.c",
    ],
)

cc_library(
    name = "libXpm",
    srcs = srcs,
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        "include",
        "include/X11",
        "src",
    ],
    deps = [
        ":libXpm_headers",
        "@x11//:x11_hdrs",
        "@xorg_xorgproto",
    ],
)
