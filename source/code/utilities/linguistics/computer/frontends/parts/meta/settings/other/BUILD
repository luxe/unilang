package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "meta_tag_existence_option",
)

hcp(
    name = "meta_warning_tag_options",
    deps = ["meta_tag_existence_option"],
)

hcp(
    name = "meta_group_name_tag_options",
    deps = ["meta_tag_existence_option"],
)

hcp(
    name = "meta_details_tag_options",
    deps = ["meta_tag_existence_option"],
)

hcp(
    name = "meta_bug_tag_options",
    deps = ["meta_tag_existence_option"],
)

hcp(
    name = "meta_brief_tag_options",
    deps = ["meta_tag_existence_option"],
)
