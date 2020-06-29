package(default_visibility = ["//visibility:public"])

hdrs = glob(
    include = [
        "X11/Xtrans/*.h",
        "X11/Xtrans/Xtrans.c",
        "X11/Xtrans/Xtranssock.c",
        "X11/Xtrans/Xtransutil.c",
        "X11/Xtrans/transport.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "Xtrans_headers",
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
        "X11/Xtrans/*.c",
    ],
    exclude = [
        "X11/Xtrans/Xtrans.c",
    ],
)

cc_library(
    name = "Xtrans",
    srcs = srcs,
    copts = [
    ],
    includes = [
        ".",
        "X11",
        "X11/Xtrans",
    ],
    #include_prefix = "X11/Xtrans",
    deps = [
        ":Xtrans_headers",
        "@xorg_xorgproto",
    ],
)
