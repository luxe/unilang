package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "java_settings",
    deps = [
    ],
)

hcp(
    name = "java_default_rule_settings",
    deps = [
        "//code/utilities/contributor:contributor",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_settings",
        "//code/utilities/code:concept_static_tree_structs",
    ],
)