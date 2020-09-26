package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(name = "method_parameter_unit_settings")

hcp(
    name = "method_parameter_settings",
    deps = [
        "//code/tools/transcompilers/unilang/options/sections:notation_settings",
        "//code/tools/transcompilers/unilang/options/sections/method/parameters:method_parameter_unit_settings",
    ],
)
