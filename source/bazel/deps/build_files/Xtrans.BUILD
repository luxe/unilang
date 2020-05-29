package(default_visibility = ["//visibility:public"])

hdrs = glob(
    include = [
        "include/X11/Xtrans/*.h",
        "include/X11/Xtrans/Xtrans.c",
        "include/X11/Xtrans/Xtransutil.c"
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
        "include/X11/Xtrans/*.c",
    ],
    exclude = [
        "include/X11/Xtrans/Xtrans.c"
    ],
)

cc_library(
    name = "Xtrans",
    srcs = srcs,
    copts = [
    ],
    includes = [
        ".",
    ],
    include_prefix = "include/X11/Xtrans",
    deps = [
        ":Xtrans_headers",
    ],
)
