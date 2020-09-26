package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "unilang_type_to_language_type_converter",
    deps = [
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/types/generic/lookup_table:type_conversion_lookup_table",
        "//code/utilities/linguistics/computer/types/generic/lookup_table:unilang_type_to_language_type_table_getter",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)
