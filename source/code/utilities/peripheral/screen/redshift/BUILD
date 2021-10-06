package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "redshift_settings",
    deps = [
    ],
)

hcp(
    name = "redshift_command_getter",
    deps = [
        "//code/utilities/peripheral/screen/redshift:redshift_settings",
    ],
)
