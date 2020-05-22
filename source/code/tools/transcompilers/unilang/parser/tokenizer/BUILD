package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "tokenizer_testing_settings",
    deps = [
        "//code/tools/transcompilers/unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/unilang/tokens:all_language_tokens",
    ],
)

hcp(
    name = "tokenizer_exception",
    deps = [
        "//code/tools/transcompilers/unilang/parser/tokenizer/file_marker",
    ],
)

hcp(
    name = "tokenizer_marker",
    deps = [
        "//code/tools/transcompilers/unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/unilang/parser:global_tokens_table_utilities",
        "//code/tools/transcompilers/unilang/parser/tokenizer:tokenizer_testing_settings",
        "//code/tools/transcompilers/unilang/parser/tokenizer/file_marker",
        "//code/tools/transcompilers/unilang/parser/tokenizer/file_marker:file_marker_adjuster",
        "//code/tools/transcompilers/unilang/user-frontend:fully_read_file",
    ],
)

hcp(
    name = "tokenizer",
    deps = [
        "//code/tools/transcompilers/unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/unilang/parser:global_tokens_table_utilities",
        "//code/tools/transcompilers/unilang/parser:parser_token",
        "//code/tools/transcompilers/unilang/parser/body_parser:file_range_location",
        "//code/tools/transcompilers/unilang/parser/tokenizer:tokenizer_exception",
        "//code/tools/transcompilers/unilang/parser/tokenizer:tokenizer_marker",
        "//code/tools/transcompilers/unilang/parser/tokenizer:tokenizer_testing_settings",
        "//code/tools/transcompilers/unilang/parser/tokenizer/file_marker",
        "//code/tools/transcompilers/unilang/tokens:get_tokens",
        "//code/tools/transcompilers/unilang/user-frontend:fully_read_file",
    ],
)
