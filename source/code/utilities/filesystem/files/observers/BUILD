package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

hcp_hdrs_derive(
    name = "filename_size_printer",
    interface_deps = [
        "//code/utilities/deps/stl/filesystem:lib"
    ],
)
