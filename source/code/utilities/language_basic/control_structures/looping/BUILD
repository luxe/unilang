package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
)

cc_library(
    name = "gmp_repeat",
    srcs = ["gmp_repeat.cpp"],
    hdrs = ["gmp_repeat.hpp"],
    deps = ["//code/utilities/math/gmp:lib"],
)
