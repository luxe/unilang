package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "regular_statement",
    deps = [
        "//code/tools/transcompilers/unilang/parser/body_parser:body_token_value",
    ],
)

hcp(
    name = "return_statement",
    deps = [
        "//code/tools/transcompilers/unilang/parser/body_parser:body_token_value",
    ],
)

hcp(
    name = "uncaught_statement",
    deps = [
        "//code/tools/transcompilers/unilang/parser/body_parser:body_token_value",
    ],
)
