package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "language_type", deps = [
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages/language_type:type_size",
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages/language_type:needed_import",
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages/language_type:language_type_category",
])
hcp(name = "needed_import", deps = [
	"type_size",
"//code/tools/transcompilers/unilang/structure/model/sections/import:import_type",
])
hcp(name = "type_size", deps = [
])

enum_cpp(name = "language_type_category",
values = 
["fundamental"
,"abstract"
])


