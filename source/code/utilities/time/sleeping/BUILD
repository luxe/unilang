package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/math/gmp:lib",
        "//code/utilities/time/clock",
    ],
)
