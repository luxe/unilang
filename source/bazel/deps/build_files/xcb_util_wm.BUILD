package(default_visibility = ["//visibility:public"])

cc_library(
    name = "xcb_util_wm",
    srcs =
        [
            "xcb/ewmh.c",
            "xcb/icccm.c",
        ],
    hdrs =
        [
            "xcb/xcb_ewmh.h",
            "xcb/xcb_icccm.h",
        ],
    includes = ["."],
    #include_prefix = "xcb",
    deps = [
        "@xcb",
    ],
)
