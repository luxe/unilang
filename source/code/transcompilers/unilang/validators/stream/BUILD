package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "token_stream_validation_exception", deps = [
"//code/transcompilers/unilang/parser/tokenizer/file_marker:file_marker",
"//code/transcompilers/unilang/parser:parser_token",
])

hcp(name = "token_validation_info", deps = [
"//code/transcompilers/unilang/parser:parser_token",
])

hcp(name = "token_stream_validator", deps = [
"//code/transcompilers/unilang/parser:parser_token",
"//code/transcompilers/unilang/validators/stream:token_validation_info",
"//code/transcompilers/unilang/options/parser:parser_settings",
"//code/transcompilers/unilang/validators/stream:token_stream_validation_exception",
"//code/utilities/types/strings/observers/counters:lib",
"//code/utilities/converters:lib",
])