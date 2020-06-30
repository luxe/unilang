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
    name = "xorg_libXdamage",
    srcs = srcs,
    hdrs = hdrs,
    includes = [
        "include",
        "include/X11/extensions",
        "src",
    ],
    deps = [
        "@x11//:x11_hdrs",
        "@xorg_libXfixes",
        "@xorg_xorgproto",
    ],
)
