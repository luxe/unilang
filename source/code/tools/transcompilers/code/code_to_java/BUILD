package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "code_to_java",
    srcs = ["main.cpp"],
    deps = [
        "//code/tools/transcompilers/code/code_to_java/program_options:lib",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/filesystem/files/creating:lib",
    ],
)
