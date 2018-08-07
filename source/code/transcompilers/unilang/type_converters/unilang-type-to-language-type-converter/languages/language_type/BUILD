package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "language_type", deps = [
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages/language_type:type_size",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages/language_type:needed_import",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages/language_type:language_type_category",
])
hcp(name = "needed_import", deps = [
	"type_size",
"//code/transcompilers/unilang/structure/sections/import:import_type",
])
hcp(name = "type_size", deps = [
])
cpp_object(name = "language_type_category")