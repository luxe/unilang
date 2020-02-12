package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "body_token_parser", deps = [
"body_token_value",
"//code/tools/transcompilers/unilang/tokens:token_name",
"//code/tools/transcompilers/unilang/parser:global_tokens_table_utilities",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/tools/transcompilers/unilang/options/parser:parser_settings",
])

hcp(name = "body_token_value", deps = [
"//code/tools/transcompilers/unilang/tokens:token_name",
"file_range_location"
])

hcp(name = "file_range_location", deps = [
"//code/tools/transcompilers/unilang/parser/tokenizer/file_marker:file_marker"
])