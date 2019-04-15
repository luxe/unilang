package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "export_file_settings", deps = [
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/transcompilers/unilang/structure/print/export_file_settings:file_type",
"//code/transcompilers/unilang/structure/print/export_file_settings:special_file_type",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
])

#what the particular exported file represents
#should we make this a struct of bools instead?
enum_cpp(
    name = "file_type",
    values = [
    
    #main
    "interface",
    "implementation",
    "data",
    
    #combined
    "data_and_interface",
    "interface_and_implementation",
    "all",
    ]
)

enum_cpp(
    name = "special_file_type",
    values = [
    "normal",
    "test",
    "constraint",
    "serialize",
    ]
)