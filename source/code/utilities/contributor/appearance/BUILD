package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "gender",
    values = [
        "male",
        "female",
        "other",
    ],
)

enum_cpp(
    name = "species",
    values = [
        "human",
        "robot",
    ],
)

hcp_hdrs_derive(
    name = "contributor_appearance",
    interface_deps = [
        "//code/utilities/contributor/appearance:gender",
        "//code/utilities/contributor/appearance:species",
    ],
)
