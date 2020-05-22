cc_binary(
    name = "tardis",
    srcs = ["tardis.c"],
    data = [":novdso"],
    includes = ["."],
    visibility = ["//visibility:public"],
    deps = [":novdso"],
)

cc_library(
    name = "novdso",
    srcs = ["novdso.c"],
    includes = ["."],
    visibility = ["//visibility:public"],
)
