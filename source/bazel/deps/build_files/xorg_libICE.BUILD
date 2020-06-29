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
    name = "Xorg_libICE_headers",
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
        #"src/icetrans.c",
        #"src/misc.c",
    ],
)

cc_library(
    name = "xorg_libICE",
    srcs = srcs,
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        ".",
        "include",
        "include/X11/ICE",
        "src",
    ],
    deps = [
        ":Xorg_libICE_headers",
        "@Xtrans",
        "@xorg_xorgproto",
    ],
)
