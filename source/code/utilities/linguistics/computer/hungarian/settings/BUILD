package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "identifier_notation_settings",
    deps = [
        "//code/utilities/linguistics/computer/hungarian/settings/characteristic:hungarian_characteristic_settings",
        "//code/utilities/linguistics/computer/hungarian/settings/type:hungarian_type_settings",
    ],
)
