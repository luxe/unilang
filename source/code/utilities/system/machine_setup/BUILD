package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "keygen_refresher",
    deps = [
        "//code/utilities/program/call:lib",
    ],
)


hcp(
    name = "machine_provisioner",
    deps = [
        "//code/utilities/fonts/bdf/complete:unilang_font_installer",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/git:git_setuper",
        "//code/utilities/system/machine_setup:keygen_refresher",
    ],
)