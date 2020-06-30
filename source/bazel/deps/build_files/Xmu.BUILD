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
    name = "Xmu_headers",
    hdrs = hdrs,
    copts = [
    ],
    includes = [
        "include",
        "include/X11/Xmu",
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
    name = "Xmu",
    srcs = srcs,
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        "include",
        "include/X11/Xmu",
        "src",
    ],
    deps = [
        ":Xmu_headers",
        "@x11//:x11_hdrs",
        "@xorg_libXt",
        "@xorg_libXext//:Xorg_libXext_headers"
    ],
)
