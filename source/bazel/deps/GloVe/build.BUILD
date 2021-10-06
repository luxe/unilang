package(default_visibility = ["//visibility:public"])

cc_library(
    name = "common",
    srcs = ["src/common.c"],
    hdrs = ["src/common.h"],
)

cc_binary(
    name = "cooccur",
    srcs = ["src/cooccur.c"],
    deps = [":common"],
)

cc_binary(
    name = "glove",
    srcs = ["src/glove.c"],
    copts = ["-Ofast"],
    deps = [":common"],
)

cc_binary(
    name = "shuffle",
    srcs = ["src/shuffle.c"],
    deps = [":common"],
)

cc_binary(
    name = "vocab_count",
    srcs = ["src/vocab_count.c"],
    deps = [":common"],
)
