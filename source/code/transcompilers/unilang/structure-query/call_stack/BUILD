package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "direct_methods_called_by_methods_getter", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/options/comment/doxygen:doxygen_parameter_direction",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/transcompilers/unilang/structure-query:argument_direction_decider",
"//code/transcompilers/unilang/structure-query/call_stack:direct_method_call_and_count",
])

hcp(name = "direct_method_call_and_count", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
])