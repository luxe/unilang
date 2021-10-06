licenses(["notice"])  # MIT-style

cc_library(
    name = "date",
    srcs = glob(["src/**/*.cpp"]),
    hdrs = glob(["include/date/**/*.h"]),
    copts = [
    ],
    defines = [],
    includes = [
        ".",
        "include",
        "include/date",
    ],
    visibility = ["//visibility:public"],
    deps = ["@curl"],
)
