package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "method_subgroup_tag_settings",
    deps = [
        "//code/tools/transcompilers/unilang/options/comment:comment_settings",
    ],
)

hcp(
    name = "method_sorting_settings",
    deps = [
        "//code/tools/transcompilers/unilang/options/sections/method/sorting/method_sort_algorithms",
    ],
)
