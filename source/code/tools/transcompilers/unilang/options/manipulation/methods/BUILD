package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "method_manipulation_settings",
    deps = [
        "//code/tools/transcompilers/unilang/options/manipulation:comment_adjustment_settings",
        "//code/tools/transcompilers/unilang/options/manipulation/methods/via_data_member:data_member_utility_function_options",
        "//code/tools/transcompilers/unilang/options/manipulation/methods/via_enum:enum_utility_function_options",
        "//code/tools/transcompilers/unilang/options/manipulation/methods/via_other_methods:method_utility_function_options",
    ],
)
