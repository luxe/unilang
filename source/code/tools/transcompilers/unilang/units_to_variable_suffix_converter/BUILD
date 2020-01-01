package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "units_to_variable_suffix_lookup_table")

hcp(name = "unit_suffix_lookuper",deps = [
"//code/tools/transcompilers/unilang/units_to_variable_suffix_converter:units_to_variable_suffix_lookup_table",
"//code/utilities/colors:lib"
])

hcp(name = "unit_measurement", deps = [
])
hcp(name = "unit_measurements_getter", deps = [
    "//code/tools/transcompilers/unilang/units_to_variable_suffix_converter:unit_measurement"
])