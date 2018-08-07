package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "existing_import_adjuster", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/utilities/types/strings/transformers/removing:lib",
])

hcp(name = "import_adjuster", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/transcompilers/unilang/structure-adjuster/imports:existing_import_adjuster",
"//code/utilities/types/sets:lib",
"//code/utilities/converters:lib",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter:unilang_type_to_language_type_converter",
])