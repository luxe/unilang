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
        "include",
        "include/X11",
        "X11",
        "src",
    ],
    deps = [
        ":Xorg_libXt_headers",
        "@xorg_libSM",
    ],
)
