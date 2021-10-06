package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:bootstrap_hcp.bzl", "bootstrap_hcp")

bootstrap_hcp(
    name = "hcp_settings",
    deps = ["//code/programs/transcompilers/hcp-compiler/official/settings:hcp_header_settings"],
)

bootstrap_hcp(
    name = "hcp_header_settings",
)
