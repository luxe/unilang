package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "enum_utility_function_options",
    deps = [
        "//code/tools/transcompilers/unilang/options/manipulation/methods/via_enum/categories:enum_utility_conversion_function_options",
        "//code/tools/transcompilers/unilang/options/manipulation/methods/via_enum/categories:enum_utility_iteration_function_options",
        "//code/tools/transcompilers/unilang/options/manipulation/methods/via_enum/categories:enum_utility_special_value_function_options",
        "//code/tools/transcompilers/unilang/options/manipulation/methods/via_enum/categories:enum_utility_subgroup_affiliation_function_options",
    ],
)
