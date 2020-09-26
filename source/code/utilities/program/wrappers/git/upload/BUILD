package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "github_uploader",
    deps = [
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/personal/hosting:hosting_repo",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/git/update:git_updater",
        "//code/utilities/program/wrappers/git/upload:github_upload_settings",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/char:lib",
        "@curl",
    ],
)

hcp(
    name = "github_upload_settings",
    deps = [
        "//code/utilities/program/wrappers/git/update:git_update_settings",
    ],
)
