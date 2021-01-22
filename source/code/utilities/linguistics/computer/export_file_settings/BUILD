package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "export_file_settings",
    deps = [
        "//code/utilities/code:code_type",
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/export_file_settings:export_path_settings",
        "//code/utilities/linguistics/computer/export_file_settings:file_type",
        "//code/utilities/linguistics/computer/export_file_settings:special_file_type",
    ],
)

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
    ],
)

enum_cpp(
    name = "special_file_type",
    values = [
        "normal",
        "test",
        "constraint",
        "serialize",
    ],
)

hcp(
    name = "export_path_settings",
    deps = [
    ],
)
