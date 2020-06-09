package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "*.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "libtiff",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        ".",
    ],
    deps = [
    ],
)
