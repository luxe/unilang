package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "literal_suffix_settings", deps = [
"floating_point_literal_settings"
])

hcp(name = "literal_suffix_getter", deps = [
"literal_suffix_settings",
"//code/tools/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_stripper",
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter:unilang_type_to_language_type_converter",
"//code/utilities/types/converters:lib"
])

hcp(name = "floating_point_literal_settings")