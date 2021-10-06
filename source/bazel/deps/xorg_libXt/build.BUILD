package(default_visibility = ["//visibility:public"])

hdrs = glob(
    include = [
        "X11/**/*.h",
        "include/**/*.h",
        "include/X11/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

cc_library(
    name = "Xorg_libXt_headers",
    hdrs = hdrs,
    copts = [
    ],
    deps = [
    ],
)

srcs = glob(
    include = [
        "src/**/*.c",
        "util/makestrs.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "xorg_libXt",
    srcs = srcs,
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        ".",
        "X11",
        "include",
        "include/X11",
        "src",
    ],
    deps = [
        ":Xorg_libXt_headers",
        "@x11//:x11_hdrs",
        "@xorg_libSM",
    ],
)
