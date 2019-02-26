package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "argument_direction_decider", deps = [
"//code/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/options/comment/doxygen:doxygen_parameter_direction",
"//code/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data_shared",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/utilities/types/strings/observers/other:lib",
])

hcp(name = "closed_box_function_checker", deps = [
"//code/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/options/comment/doxygen:doxygen_parameter_direction",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/transcompilers/unilang/structure/query:argument_direction_decider",
])

hcp(name = "is_overload_decider", deps = [
"//code/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/converters:lib",
])

hcp(name = "duplicated_type_information_with_parent_checker", deps = [
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/types/vectors/observers:lib",
])

hcp(name = "duplicated_identifier_information_with_parent_checker", deps = [
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/types/vectors/observers:lib",
])