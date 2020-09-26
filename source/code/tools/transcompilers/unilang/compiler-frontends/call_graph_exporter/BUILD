package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "call_graph_exporter",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/call_graph:call_graph_options",
        "//code/tools/transcompilers/unilang/parser/body_parser:body_token_parser",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/tools/transcompilers/unilang/structure/model/sections:structure_enums",
        "//code/utilities/contributor",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)
