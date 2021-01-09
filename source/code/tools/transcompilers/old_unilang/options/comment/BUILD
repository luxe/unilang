package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "comment_style_category")

hcp(
    name = "comment_settings",
    deps = [
        "//code/tools/transcompilers/old_unilang/options/comment:comment_grammar_settings",
        "//code/tools/transcompilers/old_unilang/options/comment:comment_style_category",
        "//code/tools/transcompilers/old_unilang/options/comment/doxygen:doxygen_block_options",
        "//code/tools/transcompilers/old_unilang/options/comment/language_default:c_comment_settings",
    ],
)
