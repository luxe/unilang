package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

cpp_object(name = "units_to_variable_suffix_lookup_table")

hcp(name = "unit_suffix_lookuper",deps = [
"//code/transcompilers/unilang/units_to_variable_suffix_converter:units_to_variable_suffix_lookup_table",
"//code/utilities/colors:lib"
])