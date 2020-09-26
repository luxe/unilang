package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    "csharp_export_settings",
    deps = [
        "//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
    ],
)
