package(default_visibility = ["//visibility:public"])

cc_library(
    name = "xdo",
    srcs = [
        "helpers.c",
        "xdo.c",
    ],
    hdrs = [
        "helpers.h",
        "xdo.h",
    ],
    copts = [
        "-DVERSION=\\\"1\\\"",
        "-D_POSIX_C_SOURCE=200809L",
    ],
    deps = [
        "@xcb",
        "@xcb_util",
        "@xcb_util_wm",
    ],
)
