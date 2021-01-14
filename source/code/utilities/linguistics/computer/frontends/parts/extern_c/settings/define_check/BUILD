package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "define_check_method")

hcp(
    name = "define_check_settings",
    deps = [
        "define_check_method",
    ],
)

hcp(
    name = "define_check_end_comment_settings",
    deps = [
        "//code/utilities/comments/language:comment_style",
    ],
)
