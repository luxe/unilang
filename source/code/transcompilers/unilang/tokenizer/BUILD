package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "tokenizer_testing_settings")

hcp(name = "tokenizer_exception", deps = [
"//code/transcompilers/unilang/file_marker:file_marker"
])

hcp(name = "tokenizer_marker", deps = [
"//code/transcompilers/unilang/file_marker:file_marker",
"//code/transcompilers/unilang/user-frontend:fully_read_file",
"//code/transcompilers/unilang/tokenizer:tokenizer_testing_settings",
"//code/transcompilers/unilang/file_marker:file_marker_adjuster",
"//code/transcompilers/unilang/tokens:global_token_table",
"//code/transcompilers/unilang/parser:global_tokens_table_utilities",
])

hcp(name = "tokenizer", deps = [
"//code/transcompilers/unilang/parser:parser_token",
"//code/transcompilers/unilang/file_marker:file_marker",
"//code/transcompilers/unilang/tokenizer:tokenizer_marker",
"//code/transcompilers/unilang/tokenizer:tokenizer_testing_settings",
"//code/transcompilers/unilang/user-frontend:fully_read_file",
"//code/transcompilers/unilang/parser:global_tokens_table_utilities",
"//code/transcompilers/unilang/tokenizer:tokenizer_exception",
"//code/transcompilers/unilang/parser/body_parser:file_range_location",
])