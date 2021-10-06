package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(name = "method_attribute_line_breaking_settings")

hcp(
    name = "method_attribute_settings",
    deps = [
        "method_attribute_line_breaking_settings",
        "method_unused_settings",
    ],
)

hcp(
    name = "method_unused_settings",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/method/attributes/specific/parts:attribute_style",
        "//code/utilities/linguistics/computer/frontends/parts/method/attributes/specific/parts:attribute_usage_note",
        "//code/utilities/linguistics/computer/frontends/parts/method/attributes/specific/parts/placements:all_method_attribute_placements",
    ],
)
