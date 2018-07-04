package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "call_graph_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/compiler-frontends/call_graph_exporter:call_graph_options",
"//code/transcompilers/unilang/structure/sections:structure_enums",
"//code/transcompilers/unilang/parser/body_parser:body_token_parser",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/transcompilers/unilang/structure:inlined_structures",
])

hcp(name = "call_graph_options")