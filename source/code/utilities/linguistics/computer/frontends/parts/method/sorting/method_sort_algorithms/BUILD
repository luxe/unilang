package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "method_sort_algorithm_types")

hcp(
    name = "method_sort_algorithms",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/method/sorting:method_subgroup_tag_settings",
        "//code/utilities/linguistics/computer/frontends/parts/method/sorting/method_sort_algorithms:method_sort_algorithm_types",
    ],
)
