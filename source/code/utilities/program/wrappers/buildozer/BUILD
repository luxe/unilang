package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "buildozer_runner",
    deps = [
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/wget:wget_downloader",
        "//code/utilities/system:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
    ],
)
