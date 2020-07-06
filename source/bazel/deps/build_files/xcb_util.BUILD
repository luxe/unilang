package(default_visibility = ["//visibility:public"])

load("@//bazel/cookbook/system:mv_file.bzl", "mv_file")

#mv_file("xmlparse_c", "expat/lib/xmlparse.c", "xmlparse.c")

cc_library(
    name = "xcb_util",
    hdrs = 
        [
            "icccm/xcb_icccm.h"
        ],
    srcs =
        [
            "icccm/icccm.c"
        ],
    includes = [".","xcb","icccm","xcb/icccm","./xcb/icccm"],
    #include_prefix = "xcb",
    deps = [
        "@xcb",
    ],
)

cc_library(
    name = "xcb_util2",
    include_prefix = "xcb",
    deps = [
        "@xcb_util",
    ],
)