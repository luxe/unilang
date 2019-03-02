package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "tokenizer_testing_settings",
    deps = [
        "//code/transcompilers/unilang/options/parser:parser_settings",
        "//code/transcompilers/unilang/tokens:all_language_tokens",
    ])

hcp(name = "tokenizer_exception", deps = [
"//code/transcompilers/unilang/parser/tokenizer/file_marker:file_marker"
])

hcp(name = "tokenizer_marker", deps = [
"//code/transcompilers/unilang/parser/tokenizer/file_marker:file_marker",
"//code/transcompilers/unilang/user-frontend:fully_read_file",
"//code/transcompilers/unilang/parser/tokenizer:tokenizer_testing_settings",
"//code/transcompilers/unilang/parser/tokenizer/file_marker:file_marker_adjuster",
"//code/transcompilers/unilang/parser:global_tokens_table_utilities",
"//code/transcompilers/unilang/options/parser:parser_settings",
])

hcp(name = "tokenizer", deps = [
"//code/transcompilers/unilang/parser:parser_token",
"//code/transcompilers/unilang/parser/tokenizer/file_marker:file_marker",
"//code/transcompilers/unilang/parser/tokenizer:tokenizer_marker",
"//code/transcompilers/unilang/parser/tokenizer:tokenizer_testing_settings",
"//code/transcompilers/unilang/user-frontend:fully_read_file",
"//code/transcompilers/unilang/parser:global_tokens_table_utilities",
"//code/transcompilers/unilang/parser/tokenizer:tokenizer_exception",
"//code/transcompilers/unilang/parser/body_parser:file_range_location",
"//code/transcompilers/unilang/tokens:get_tokens",
"//code/transcompilers/unilang/options/parser:parser_settings",
])