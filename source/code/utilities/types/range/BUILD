package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "range_shrinker",
    deps = [
        "//code/utilities/data_structures/range",
    ],
)

hcp_hdrs_derive(
    name = "create_range_from_string",
    interface_deps = [
        "//code/utilities/data_structures/range:range",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
    ],
)

hcp_hdrs_derive(
    name = "interval_fully_contained_in_interval",
    interface_deps = [
        "//code/utilities/data_structures/range:range",
    ],
)

hcp_hdrs_derive(
    name = "intervals_overlap",
    interface_deps = [
        "//code/utilities/data_structures/range:range",
    ],
)
