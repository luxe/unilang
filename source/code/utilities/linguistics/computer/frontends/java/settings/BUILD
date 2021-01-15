package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "java_settings",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts:portion_options",
        "//code/utilities/linguistics/computer/frontends/parts:notation_settings",
        "//code/tools/transcompilers/old_unilang/options:general_options",
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