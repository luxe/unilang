package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "function_table_of_contents_printer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/structure-printer/export_file_settings:export_file_settings",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
])