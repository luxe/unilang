package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "header_block_comment_getter",
    deps = [
        "//code/tools/transcompilers/old_unilang/comment_creator",
        "//code/utilities/linguistics/computer/frontends/parts/sections/import:shared_headers_block_comment",
    ],
)
