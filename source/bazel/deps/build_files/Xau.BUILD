package(default_visibility = ["//visibility:public"])

hdrs = glob(
    include = [
        "*.h",
        "include/X11/*.h",
    ],
    exclude = [
    ],
)

cc_library(
    name = "Xau_headers",
    hdrs = hdrs,
    copts = [
    ],
    includes = [
        ".",
    ],
    deps = [
    ],
)

srcs = glob(
    include = [
        "*.c",
    ],
    exclude = [
        "X11/Xtrans/Xtrans.c",
    ],
)

cc_library(
    name = "Xau",
    srcs = srcs,
    copts = [
    ],
    includes = [
        ".",
        "include",
        "include/X11",
    ],
    deps = [
        ":Xau_headers",
        "@xorg_xorgproto",
    ],
)
