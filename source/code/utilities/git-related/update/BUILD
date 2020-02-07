package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "git_update_settings", deps = [])

hcp(name="git_updater", deps = [
    "//code/utilities/shell:lib",
    "//code/utilities/git-related/update:git_update_settings",
])