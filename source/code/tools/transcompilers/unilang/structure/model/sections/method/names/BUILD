package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "method_names_section",
    deps = [
        "alternative_expression_name",
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "alternative_expression_name",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)
