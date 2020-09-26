package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "compile_unit",
    deps = [
        "//code/tools/transcompilers/unilang/options:export_settings",
        "//code/utilities/contributor",
    ],
)

hcp(
    name = "compile_units",
    deps = ["compile_unit"],
)

enum_cpp(
    name = "chosen_exporter",
    values =
        [
            "none",
            "uber",
            "f2si",
            "trevor",
        ],
)
