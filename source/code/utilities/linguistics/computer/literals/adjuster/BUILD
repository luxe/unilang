package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "literal_adjuster",
    deps = [
        "//code/tools/transcompilers/unilang/structure/print:shared_printer",
        "//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
        "//code/tools/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/literals/getter:cpp_literal_suffix_settings",
        "//code/utilities/linguistics/computer/literals/getter:java_literal_suffix_settings",
        "//code/utilities/linguistics/computer/literals/getter:literal_suffix_getter",
        "//code/utilities/linguistics/computer/literals/getter/data:floating_point_literal_settings",
        "//code/utilities/linguistics/computer/literals/getter/data:literal_suffix_settings",
        "//code/utilities/types/vectors/observers:lib",
    ],
)
