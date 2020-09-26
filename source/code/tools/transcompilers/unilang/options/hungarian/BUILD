package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "identifier_notation_settings",
    deps = [
        "//code/tools/transcompilers/unilang/options/hungarian/characteristic:hungarian_characteristic_settings",
        "//code/tools/transcompilers/unilang/options/hungarian/type:hungarian_type_settings",
    ],
)
