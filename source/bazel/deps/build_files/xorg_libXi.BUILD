package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "include/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "src/**/*.c",
    ],
    exclude = [
        "src/XFreeLst.c",
    ],
)

cc_library(
    name = "xorg_libXi",
    srcs = srcs,
    hdrs = hdrs,
    includes = [
        "include",
        "include/X11/extensions",
        "src",
    ],
    deps = [
        "@xorg_xorgproto",
        "@x11//:x11_hdrs",
        "@xorg_libXext//:Xorg_libXext_headers",
    ],
)
