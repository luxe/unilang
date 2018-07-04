package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "file_extension_lookup_table", deps = [
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
"//code/transcompilers/unilang/file_extension_getter/language_extensions:language_extensions",
])

hcp(name = "language_extension_deriver", deps = [
"//code/transcompilers/unilang/file_extension_getter/language_extensions:language_extensions"
])

hcp(name = "file_extension_lookup_table_getter", deps = [
"//code/transcompilers/unilang/file_extension_getter/lookup_table:file_extension_lookup_table",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
"//code/transcompilers/unilang/file_extension_getter/language_extensions:language_extensions",
"//code/transcompilers/unilang/file_extension_getter/lookup_table:language_extension_deriver",
"//code/utilities/types/map:lib"
])