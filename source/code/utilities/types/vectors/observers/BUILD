package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/observers/char:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/data_structures/position:position",
    ],
)

hcp(
    name = "size_frequency_counter",
    deps = [
        "//code/utilities/data_structures/counters/unique_counter",
    ],
)

hcp(
    name = "character_index_frequency",
    deps = [
        "//code/utilities/data_structures/counters/unique_counter",
    ],
)

hcp(
    name = "index_range_algorithms",
    deps = [
        "//code/utilities/data_structures/range",
    ],
)
