package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "function_table_of_contents_printer", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/structure/print/export_file_settings:export_file_settings",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/types/strings/transformers/other:lib",
])