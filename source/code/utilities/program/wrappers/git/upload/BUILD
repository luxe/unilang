package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "github_uploader",
    interface_deps = [
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/personal/hosting:hosting_repo",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/git/update:git_updater",
        "//code/utilities/program/wrappers/git/upload:github_upload_settings",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/deps/external/curl:lib",
    ],
)

hcp_hdrs_derive(
    name = "github_upload_settings",
    interface_deps = [
        "//code/utilities/program/wrappers/git/update:git_update_settings",
    ],
)
