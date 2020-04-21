package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="github_uploader", deps = [
    "//code/utilities/types/char:lib",
    "//code/utilities/program/call:lib",
    "//code/utilities/streams/filestreams/read_all:lib",
    "//code/utilities/filesystem/files/getting:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/program/wrappers/git/update:git_updater",
    "//code/utilities/program/wrappers/git/upload:github_upload_settings",
        "@curl",
])

hcp(name="github_upload_settings", deps = [
    "//code/utilities/program/wrappers/git/update:git_update_settings",
])