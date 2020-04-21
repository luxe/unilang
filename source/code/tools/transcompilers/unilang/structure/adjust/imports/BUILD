package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "existing_import_adjuster", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/utilities/types/strings/transformers/removing:lib",
])

hcp(name = "import_adjuster", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/tools/transcompilers/unilang/structure/adjust/imports:existing_import_adjuster",
"//code/utilities/types/sets:lib",
"//code/utilities/types/converters:lib",
"//code/utilities/linguistics/computer/types/generic:unilang_type_to_language_type_converter",
])