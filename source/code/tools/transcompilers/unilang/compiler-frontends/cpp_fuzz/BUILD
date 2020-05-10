package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "cpp_fuzz_exporter", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/utilities/contributor:contributor",
"//code/tools/transcompilers/unilang/options/language-specific/cpp:cpp_fuzz_export_settings",
"//code/tools/transcompilers/unilang/structure/model/sections:structure_enums",
"//code/tools/transcompilers/unilang/parser/body_parser:body_token_parser",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
])