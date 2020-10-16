package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "random_gmp",
    deps = [
        "//code/utilities/math/gmp:lib",
        "//code/utilities/random/gmp:fwd",
    ],
)

cc_library(
    name = "fwd",
    srcs = ["fwd.cpp"],
    hdrs = ["fwd.hpp"],
    deps = [
        "//code/utilities/math/gmp:lib",
    ],
)
