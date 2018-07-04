package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "body_token_parser", deps = [
"body_token_value",
"//code/transcompilers/unilang/tokens:token_name",
"//code/transcompilers/unilang/parser:global_tokens_table_utilities",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/trimming:lib"
])

hcp(name = "body_token_value", deps = [
"//code/transcompilers/unilang/tokens:token_name",
"file_range_location"
])

hcp(name = "file_range_location", deps = [
"//code/transcompilers/unilang/file_marker:file_marker"
])