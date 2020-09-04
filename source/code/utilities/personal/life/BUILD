package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "company_getter",
    deps = [
        "//code/utilities/github:github_ssh_url_getter",
    ],
)
