package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "token_stream_validation_exception",
    deps = [
        "//code/tools/transcompilers/unilang/parser:parser_token",
        "//code/tools/transcompilers/unilang/parser/tokenizer/file_marker",
    ],
)

hcp(
    name = "token_validation_info",
    deps = [
        "//code/tools/transcompilers/unilang/parser:parser_token",
    ],
)

hcp(
    name = "token_stream_validator",
    deps = [
        "//code/tools/transcompilers/unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/unilang/parser:parser_token",
        "//code/tools/transcompilers/unilang/validators/stream:token_stream_validation_exception",
        "//code/tools/transcompilers/unilang/validators/stream:token_validation_info",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/counters:lib",
    ],
)
