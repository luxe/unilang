package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "method_sort_algorithm_types")

hcp(
    name = "method_sort_algorithms",
    deps = [
        "//code/tools/transcompilers/unilang/options/sections/method/sorting:method_subgroup_tag_settings",
        "//code/tools/transcompilers/unilang/options/sections/method/sorting/method_sort_algorithms:method_sort_algorithm_types",
    ],
)
