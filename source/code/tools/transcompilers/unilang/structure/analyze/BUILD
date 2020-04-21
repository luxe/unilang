package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "structure_static_analyzer", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/static_analysis:static_analysis_settings",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/utilities/types/converters:lib",
"//code/utilities/types/sets:lib",
"//code/tools/transcompilers/unilang/structure/query:closed_box_function_checker",
":error_message",
"//code/tools/transcompilers/unilang/structure/analyze:error_message_printer",
"//code/tools/transcompilers/unilang/structure/analyze:error_message_getter",
])

hcp(name = "error_message", deps = [
"//code/tools/transcompilers/unilang/parser/body_parser:file_range_location",
])

hcp(name = "error_message_printer", deps = [
"//code/tools/transcompilers/unilang/options/static_analysis:static_analysis_settings",
"//code/tools/transcompilers/unilang/structure/analyze:error_message",
])

hcp(name = "error_message_getter", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/static_analysis:static_analysis_settings",
"//code/tools/transcompilers/unilang/structure/analyze:error_message",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/utilities/types/converters:lib",
"//code/utilities/types/sets:lib",
"//code/tools/transcompilers/unilang/structure/query:closed_box_function_checker",
"//code/tools/transcompilers/unilang/structure/query:duplicated_type_information_with_parent_checker",
"//code/tools/transcompilers/unilang/structure/query:duplicated_identifier_information_with_parent_checker",
])