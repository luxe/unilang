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
    name = "Xorg_libXext_headers",
    hdrs = hdrs,
    copts = [
    ],
    includes = [
        ".",
        "X11",
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
    ],
)

cc_library(
    name = "xorg_libXext",
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
        ":Xorg_libXext_headers",
        "@Xau//:Xau_headers",
        "@x11//:x11_hdrs",
        "@xorg_xorgproto",
    ],
)
