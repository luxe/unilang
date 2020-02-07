package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="github_uploader", deps = [
    "//code/utilities/types/char:lib",
    "//code/utilities/shell:lib",
    "//code/utilities/streams/filestreams/read_all:lib",
    "//code/utilities/filesystem/files/getting:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/git-related/update:git_updater",
    "//code/utilities/git-related/upload:github_upload_settings",
        "@curl",
])

hcp(name="github_upload_settings", deps = [
    "//code/utilities/git-related/update:git_update_settings",
])