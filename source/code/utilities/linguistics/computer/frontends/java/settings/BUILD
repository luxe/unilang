package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "java_settings",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts:module_settings",
    ],
)

hcp(
    name = "java_default_rule_settings",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_settings",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings/organizations:organization",
        "//code/utilities/personal/life:company_getter",
        "//code/utilities/program/common_actions/exits:lib",
    ],
)
