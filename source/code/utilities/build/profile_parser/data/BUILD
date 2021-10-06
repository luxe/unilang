package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "duration_file",
    deps = [],
)

hcp_hdrs_derive(
    name = "owned_duration_file",
    interface_deps = [
        "//code/utilities/build/profile_parser/data:duration_file",
    ],
)

hcp_hdrs_derive(
    name = "flat_owned_duration_file",
    interface_deps = [
        "//code/utilities/build/profile_parser/data:duration_file",
    ],
)
