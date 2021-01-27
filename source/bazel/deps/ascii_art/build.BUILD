package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = ["ascii_art.c"],
    hdrs = ["ascii_art.h"],
)

cc_binary(
    name = "sample",
    srcs = ["sample.c"],
    deps = ["lib"],
)
