package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "mermaid_graph_orientation")

hcp(
    "mermaid_settings",
    deps = [
        "//code/tools/transcompilers/old_unilang/design/normal:method_sorter",
        "//code/tools/transcompilers/old_unilang/options:general_options",
        "//code/tools/transcompilers/old_unilang/options/language-specific/mermaid:mermaid_graph_orientation",
        "//code/tools/transcompilers/old_unilang/options/manipulation:struct_manipulation_settings",
        "//code/utilities/linguistics/computer/frontends/parts:portion_options",
    ],
)
