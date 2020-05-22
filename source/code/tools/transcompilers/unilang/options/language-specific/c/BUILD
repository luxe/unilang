package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object("c_language_version")

hcp(
    "c_export_settings",
    deps = [
        "//code/tools/transcompilers/unilang/options:general_options",
        "//code/tools/transcompilers/unilang/options:test_wrapper_options",
        "//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
        "//code/tools/transcompilers/unilang/options/sections:portion_options",
    ],
)
