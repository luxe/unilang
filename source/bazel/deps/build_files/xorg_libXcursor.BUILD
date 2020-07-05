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
    ],
)

cc_library(
    name = "xorg_libXcursor",
    srcs = srcs,
    hdrs = hdrs,
    includes = [
        "include",
        "include/X11/Xcursor",
        "src",
    ],
    deps = [
        "@x11//:x11_hdrs",
        "@xorg_xorgproto",
        "@xorg_libXt//:Xorg_libXt_headers",
        "@xorg_libXrender//:Xrender_headers",
    ],
)
