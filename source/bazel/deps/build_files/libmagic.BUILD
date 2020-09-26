package(default_visibility = ["//visibility:public"])

cc_library(
    name = "libmagic",
    srcs = glob(["src/**/*.c"]),
    hdrs = glob(["src/**/*.h"]) + ["config.h"],
    defines = ["HAVE_CONFIG_H"],
    includes = [
        ".",
        "src",
    ],
    linkopts = [],
    deps = [
        "@zlib//:zlib",
    ],
)
