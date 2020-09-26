package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    "dzslides_settings",
    deps = [
        "//code/tools/transcompilers/unilang/options:general_options",
        "//code/tools/transcompilers/unilang/options/language-specific/dzslides:dzslide_creation_settings",
        "//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_settings",
        "//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
        "//code/tools/transcompilers/unilang/options/sections:portion_options",
    ],
)

hcp(
    "dzslide_creation_settings",
    deps = [
    ],
)
