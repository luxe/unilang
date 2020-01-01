package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/unilang:generate_unilang_token_files.bzl", "generate_unilang_token_files")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "token_builder",
    deps = [
        "//code/tools/transcompilers/unilang/tokens:all_language_tokens",
        "//code/tools/transcompilers/unilang/tokens:token_name",
        "//code/utilities/converters:lib",
    ]
)