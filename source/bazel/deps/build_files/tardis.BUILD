cc_binary(
    name = "tardis",
    srcs = ["tardis.c"],
    includes = ["."],
    data = [":novdso"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "novdso",
    srcs = ["novdso.c"],
    includes = ["."],
    visibility = ["//visibility:public"],
)
