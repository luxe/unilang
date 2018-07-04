package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "equivalent_type_deriver", deps = [
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:equivalent_language_types",
"//code/utilities/types:tri_bool",
])

hcp(name = "type_conversion_lookup_table", deps = [
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:equivalent_language_types"
])

hcp(name = "unilang_type_to_language_type_table_getter", deps = [
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/lookup_table:type_conversion_lookup_table",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/lookup_table:equivalent_type_deriver",
"//code/utilities/types/map:lib"
])