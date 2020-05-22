package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "mermaid_graph_orientation")

hcp(
    "mermaid_settings",
    deps = [
        "//code/tools/transcompilers/unilang/design/normal:method_sorter",
        "//code/tools/transcompilers/unilang/options:general_options",
        "//code/tools/transcompilers/unilang/options/language-specific/mermaid:mermaid_graph_orientation",
        "//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
        "//code/tools/transcompilers/unilang/options/sections:portion_options",
    ],
)
