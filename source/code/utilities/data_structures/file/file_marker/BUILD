package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

hcp_hdrs_derive(
    name = "file_marker",
)

hcp_hdrs_derive(
    name = "file_marker_adjuster",
    interface_deps = ["file_marker"],
)
