package(default_visibility = ["//visibility:public"])

licenses(["notice"])

filegroup(
    name = "config_h",
    srcs = ["config.h"],
)

cc_library(
    name = "snappy",
    srcs = [
        "snappy.cc",
        "snappy-c.cc",
        "snappy-internal.h",
        "snappy-sinksource.cc",
        "snappy-stubs-internal.cc",
        "snappy-stubs-internal.h",
        ":config_h",
    ],
    hdrs = [
        "snappy.h",
        "snappy-c.h",
        "snappy-sinksource.h",
        "snappy-stubs-public.h",
    ],
    copts = ["-DHAVE_CONFIG_H"],
    includes = ["."],
    deps = ["@net_zlib_zlib//:zlib"],
)

cc_library(
    name = "snappy-test-lib",
    srcs = [
        "snappy-test.cc",
        ":config_h",
    ],
    hdrs = ["snappy-test.h"],
    copts = ["-DHAVE_CONFIG_H"],
    includes = ["."],
    deps = [
        ":snappy",
        "@com_google_googletest//:gtest",
    ],
)

cc_test(
    name = "snappy-test",
    srcs = [
        "snappy_unittest.cc",
        ":config_h",
    ],
    copts = ["-DHAVE_CONFIG_H"],
    deps = [":snappy-test-lib"],
)
