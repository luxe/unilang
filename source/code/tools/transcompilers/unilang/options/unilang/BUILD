package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "unilang_section_settings")

hcp(name = "unilang_general_settings")

hcp(
    name = "unilang_export_settings",
    deps = [
        "unilang_general_settings",
        "unilang_section_settings",
        "//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
    ],
)
