package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "subgroup_methods",
    deps = [
        "//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
    ],
)

hcp(
    name = "subgroup_sorted_methods",
    deps = [
        "subgroup_methods",
    ],
)
