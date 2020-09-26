package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "enum_arg",
    deps = [
        "enum_arg_subscribed_subgroup",
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "enum_arg_subscribed_subgroup",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)
