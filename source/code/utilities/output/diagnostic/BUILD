package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object("diagnostic_color")

cpp_object("diagnostic_stream")

hcp_hdrs_derive(
    name = "diagnostic_settings",
    interface_deps = [
        "//code/utilities/output/diagnostic:diagnostic_color",
        "//code/utilities/output/diagnostic:diagnostic_stream",
    ],
)

hcp_hdrs_derive(
    name = "diagnostic_printer",
    interface_deps = [
        "//code/utilities/output/diagnostic:diagnostic_settings",
        "//code/utilities/types/strings/transformers/colors:string_colorizer",
    ],
)
