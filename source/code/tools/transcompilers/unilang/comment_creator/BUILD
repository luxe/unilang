package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "comment_creator",
    deps = [
        "//code/tools/transcompilers/unilang/options/comment/language_default:c_comment_settings",
        "//code/utilities/language_basic/relational_comparing:lib",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
    ],
)
