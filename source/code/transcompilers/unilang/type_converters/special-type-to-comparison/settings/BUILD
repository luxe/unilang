package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "special_comparison_functions", deps = [
])

hcp(name = "special_comparison_settings", deps = [
"special_comparison_type",
"special_type_comparison_builder",
])

hcp(name = "special_comparison_type", deps = [
"//code/transcompilers/unilang/parser/body_parser:body_token_value"
])

hcp(name = "special_type_comparison_builder", deps = [
"special_comparison_type",
"special_comparison_functions",
"//code/utilities/types/vectors/operators:lib",
"//code/utilities/converters:lib",
])
