package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "json_function_name_getter", deps = [
"//code/transcompilers/unilang/type_converters/type-to-json-serialization-call/settings:json_function_settings",
"//code/transcompilers/unilang/options/language-specific:c_language_version",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_stripper",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter:unilang_type_to_language_type_converter",
"//code/transcompilers/unilang/type_converters/type-to-json-serialization-call/settings:json_function_name",
"//code/utilities/converters:lib",
])