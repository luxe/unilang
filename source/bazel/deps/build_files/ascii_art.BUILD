package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    hdrs = ["ascii_art.h"],
    srcs = ["ascii_art.c"],
)

cc_binary(
    name = "sample",
    srcs = ["sample.c"],
    deps = ["lib"],
)