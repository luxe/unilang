package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "entire_body_parser",
    deps = [
        "//code/tools/transcompilers/unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/unilang/parser:global_tokens_table_utilities",
        "//code/tools/transcompilers/unilang/parser/entire_body_parser:body_tokenizer",
        "//code/tools/transcompilers/unilang/parser/entire_body_parser:nested_body_tokens",
        "//code/tools/transcompilers/unilang/structure/model/sections/method/body:function_body",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
    ],
)

cpp_object("forward_decls")

hcp(
    name = "nested_body_tokens",
    deps = [
        "//code/tools/transcompilers/unilang/parser/body_parser:body_token_value",
        "//code/tools/transcompilers/unilang/parser/entire_body_parser:forward_decls",
        "@boost//:container",
        "@boost//:variant",
    ],
)

hcp(
    name = "body_tokenizer",
    deps = [
        "//code/tools/transcompilers/unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/unilang/parser:global_tokens_table_utilities",
        "//code/tools/transcompilers/unilang/parser/entire_body_parser:nested_body_tokens",
        "//code/tools/transcompilers/unilang/structure/model/sections/method/body:function_body",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
    ],
)
