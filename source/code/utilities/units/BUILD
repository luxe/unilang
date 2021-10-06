package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

#see also:
#https://www.hillelwayne.com/post/frink/

cpp_object(name = "units_to_variable_suffix_lookup_table")

hcp(
    name = "unit_suffix_lookuper",
    deps = [
        "//code/utilities/output/printers:terminal",
        "//code/utilities/units:units_to_variable_suffix_lookup_table",
    ],
)

hcp(
    name = "unit_measurement",
    deps = [
    ],
)

hcp(
    name = "unit_measurements_getter",
    deps = [
        "//code/utilities/units:unit_measurement",
    ],
)
