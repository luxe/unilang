package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "header_block_comment_getter",
    deps = [
        "//code/utilities/comments/code:comment_creator",
        "//code/utilities/linguistics/computer/frontends/parts/header/settings:shared_headers_block_comment",
    ],
)
