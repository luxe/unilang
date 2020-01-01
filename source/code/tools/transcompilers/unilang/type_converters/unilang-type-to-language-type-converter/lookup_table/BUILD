package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "equivalent_type_deriver", deps = [
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:equivalent_language_types",
"//code/utilities/types:tri_bool",
])

hcp(name = "type_conversion_lookup_table", deps = [
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:equivalent_language_types"
])

hcp(name = "unilang_type_to_language_type_table_getter", deps = [
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/lookup_table:type_conversion_lookup_table",
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/lookup_table:equivalent_type_deriver",
"//code/utilities/types/map:lib"
])