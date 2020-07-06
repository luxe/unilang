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
    name = "Xorg_libXtst_headers",
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
    name = "xorg_libXtst",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        "include",
        "src",
    ],
    deps = [
        "@x11//:x11_hdrs",
        "@xorg_libXext",
        "@xorg_libXi",
        "@xorg_xorgproto",
    ],
)
