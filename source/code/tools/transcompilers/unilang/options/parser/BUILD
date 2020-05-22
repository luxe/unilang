package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "input_file_settings")

hcp(name = "macro_resolving_settings")

hcp(
    name = "parser_settings",
    deps = [
        "input_file_settings",
        "macro_resolving_settings",
        "tokenize_settings",
    ],
)

hcp(
    name = "tokenize_settings",
    deps = [
        "//code/tools/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
        "//code/tools/transcompilers/unilang/tokens:all_language_tokens",
    ],
)
