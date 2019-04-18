package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/unilang:generate_unilang_token_files.bzl", "generate_unilang_token_files")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "unique_tokens_checker",
    deps = [
        "//code/transcompilers/unilang/tokens:generic_token",
        "//code/transcompilers/unilang/tokens:get_tokens",
        "//code/transcompilers/unilang/language-and-theme-creator/sublime:global",
        "//code/transcompilers/unilang/language-and-theme-creator/sublime:unilang_file_creator",
        "//code/utilities/types/general:lib",
        "//code/utilities/exits:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        ]
)