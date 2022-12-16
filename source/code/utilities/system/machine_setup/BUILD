package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "keygen_refresher",
    interface_deps = [
        "//code/utilities/program/call:lib",
    ],
)

hcp_hdrs_derive(
    name = "machine_provisioner",
    interface_deps = [
        "//code/utilities/fonts/bdf/complete:unilang_font_installer",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/git:git_setuper",
        "//code/utilities/system/machine_setup:keygen_refresher",
    ],
)
