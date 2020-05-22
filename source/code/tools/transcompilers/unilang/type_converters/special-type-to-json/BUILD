package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "special_type_json_specifier_getter",
    deps = [
        "//code/tools/transcompilers/unilang/type_converters/special-type-to-json/settings:special_json_specifier_settings",
        "//code/tools/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_stripper",
        "//code/utilities/linguistics/computer/types/generic:unilang_type_to_language_type_converter",
        "//code/utilities/types/converters:lib",
    ],
)
