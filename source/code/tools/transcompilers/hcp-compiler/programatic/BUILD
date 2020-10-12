package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")

hcp(
    name = "header_getter",
    deps = [
        "//code/tools/transcompilers/hcp-compiler/official/unicode_parser_symbols:lib",
        "//code/utilities/types/converters:lib",
        "//code/tools/transcompilers/hcp-compiler/programatic/data:headers",
    ],
)
hcp(
    name = "function_getter",
    deps = [
        "//code/tools/transcompilers/hcp-compiler/official/unicode_parser_symbols:lib",
        "//code/utilities/types/converters:lib",
        "//code/tools/transcompilers/hcp-compiler/programatic/data:function",
    ],
)