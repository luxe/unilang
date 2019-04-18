package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")


hcp(name = "task_executer", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/language-and-theme-creator/sublime:global",
"//code/transcompilers/unilang/language-and-theme-creator/sublime:unilang_file_creator",
"//code/utilities/types/general:lib",
"//code/utilities/exits:lib",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/types/vectors/operators:lib",
"//code/transcompilers/unilang/tokens:get_tokens",
"//code/transcompilers/unilang/tokens/uniqueness:unique_tokens_checker",
"//code/transcompilers/unilang/language-and-theme-creator/font:unilang_font_creator"
])

cc_binary(
    name = "language-and-theme-creator",
    srcs = ["main.cpp"],
    deps = ["task_executer"]
)
