package(default_visibility = ["//visibility:public"])

cc_library(
    name = "xdo",
    hdrs = [
        "xdo.h",
        "helpers.h",
    ],
    srcs = [
        "xdo.c",
        "helpers.c",
    ],
    copts = ["-DVERSION=\"1\""],
    deps = [
        "@xcb",
        "@xcb_util",
        "@xcb_util_wm",
    ],
)
