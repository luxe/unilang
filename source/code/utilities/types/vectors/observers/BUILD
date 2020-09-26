package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/observers/char:lib",
    ],
)

hcp(
    name = "size_frequency_counter",
    deps = [
        "//code/utilities/data_structures/counters/unique_counter",
    ],
)
