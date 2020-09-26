package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/unilang:generate_unilang_token_files.bzl", "generate_unilang_token_files")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:gtest.bzl", "gtest")

hcp(
    name = "unique_tokens_checker",
    deps = [
        "//code/tools/transcompilers/unilang/language-and-theme-creator/sublime:global",
        "//code/tools/transcompilers/unilang/language-and-theme-creator/sublime:unilang_file_creator",
        "//code/tools/transcompilers/unilang/tokens:generic_token",
        "//code/tools/transcompilers/unilang/tokens:get_tokens",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

gtest(
    name = "uniqueness_test",
    deps = [
        "//code/tools/transcompilers/unilang/tokens:get_tokens",
        "//code/tools/transcompilers/unilang/tokens/uniqueness:unique_tokens_checker",
    ],
)
