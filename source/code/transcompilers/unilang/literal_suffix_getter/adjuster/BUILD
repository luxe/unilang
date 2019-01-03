package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "literal_adjuster", deps = [
"//code/transcompilers/unilang/literal_suffix_getter/getter:floating_point_literal_settings",
"//code/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/structure-printer/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/literal_suffix_getter/getter:literal_suffix_settings",
"//code/transcompilers/unilang/literal_suffix_getter/getter:literal_suffix_getter",
"//code/utilities/types/vectors/observers:lib"
])