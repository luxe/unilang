package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "matrix",
    hdrs = [
        "matrix.h",
    ],
    srcs = [
        "matrix.c",
    ],
)

filegroup(
    name = "data",
    srcs = [
        "rc.def",
    ],
)

cc_binary(
    name = "main",
    srcs = [
        "defrc.c",
        "rc.c",
    ],
    data = [
        ":data",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":matrix",
        "@glut",
        "@x11",
    ],
)
