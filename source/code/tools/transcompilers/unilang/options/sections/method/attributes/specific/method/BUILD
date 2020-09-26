package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(name = "method_attribute_line_breaking_settings")

hcp(
    name = "method_attribute_settings",
    deps = [
        "method_attribute_line_breaking_settings",
        "method_unused_settings",
    ],
)

hcp(
    name = "method_unused_settings",
    deps = [
        "//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts:attribute_style",
        "//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts:attribute_usage_note",
        "//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts/placements:all_method_attribute_placements",
    ],
)
