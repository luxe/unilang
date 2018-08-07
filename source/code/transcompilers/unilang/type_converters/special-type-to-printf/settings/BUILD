package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "special_printf_specifier_settings", deps = [
"special_printf_type",
"special_type_printf_builder",
])

hcp(name = "special_printf_type", deps = [
"//code/transcompilers/unilang/parser/body_parser:body_token_value"
])

hcp(name = "special_type_printf_builder", deps = [
"special_printf_type",
"//code/utilities/converters:lib",
"//code/utilities/types/vectors/operators:lib",
])