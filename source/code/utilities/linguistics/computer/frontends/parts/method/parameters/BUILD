package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(name = "method_parameter_unit_settings")

hcp(
    name = "method_parameter_settings",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts:notation_settings",
        "//code/utilities/linguistics/computer/frontends/parts/method/parameters:method_parameter_unit_settings",
    ],
)
