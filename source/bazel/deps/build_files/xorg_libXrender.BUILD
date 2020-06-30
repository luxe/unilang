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
    name = "Xrender_headers",
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
    name = "xorg_libXrender",
    srcs = srcs,
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        "include",
        "include/X11/extensions",
        "src",
    ],
    deps = [
        ":Xrender_headers",
        "@x11//:x11_hdrs",
        "@xorg_libXext//:Xorg_libXext_headers",
        "@xorg_xorgproto",
    ],
)
