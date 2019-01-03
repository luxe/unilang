package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "structure_static_analyzer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/static_analysis:static_analysis_settings",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/sets:lib",
"//code/transcompilers/unilang/structure-query:closed_box_function_checker",
":error_message",
])

hcp(name = "error_message", deps = [
"//code/transcompilers/unilang/parser/body_parser:file_range_location",
])