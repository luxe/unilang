package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "random_gmp",
    deps = [
        "//code/utilities/math/gmp:lib",
        "//code/utilities/types/strings/observers/hex:lib",
    ],
)
