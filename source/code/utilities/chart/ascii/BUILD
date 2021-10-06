package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "chart_get_settings",
    interface_deps = [
        "//code/utilities/data_structures/color:rgb_part_range",
    ],
)

hcp_hdrs_derive(
    name = "chart_getter",
    interface_deps = [
        "//code/utilities/chart/ascii:chart_get_settings",
        "//code/utilities/math",
        "//code/utilities/types/strings/creators:lib",
        "//code/utilities/types/strings/observers/padding:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/strings/transformers/colors:string_colorizer",
    ],
)
