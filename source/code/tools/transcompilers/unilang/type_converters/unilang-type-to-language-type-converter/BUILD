package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "unilang_type_to_language_type_converter",deps = [
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/lookup_table:type_conversion_lookup_table",
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/lookup_table:unilang_type_to_language_type_table_getter",
"//code/utilities/types/map:lib",
"//code/utilities/types/strings/transformers/casing:lib"
])