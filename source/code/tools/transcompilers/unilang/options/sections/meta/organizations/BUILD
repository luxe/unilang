package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")

hcp(
    name = "address",
)

hcp(
    name = "organization",
    deps = ["address"],
)
