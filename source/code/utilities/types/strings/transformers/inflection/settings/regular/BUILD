package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(name = "inflection")

hcp(
    name = "plural_inflections",
    deps = [
        "inflection",
    ],
)

hcp(
    name = "singular_inflections",
    deps = [
        "inflection",
    ],
)
