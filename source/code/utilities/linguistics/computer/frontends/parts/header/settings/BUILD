package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "implicit_header_comment_settings",
    deps = [],
)

hcp(
    name = "import_options",
    deps = [
        "//code/utilities/comments/code/settings:comment_settings",
        "//code/utilities/comments/doxygen/settings:doxygen_block_options",
        "//code/utilities/linguistics/computer/frontends/parts/header/settings:implicit_header_comment_settings",
        "//code/utilities/linguistics/computer/frontends/parts/header/settings:import_relation_label_settings",
        "//code/utilities/linguistics/computer/frontends/parts/header/settings:shared_headers_block_comment",
    ],
)

hcp(
    name = "import_relation_label_settings",
    deps = [],
)

hcp(
    name = "shared_headers_block_comment",
    deps = [
        "//code/utilities/comments/code/settings:comment_settings",
    ],
)
