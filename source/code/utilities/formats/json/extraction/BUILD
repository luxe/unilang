package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "json_extraction_settings",
    interface_deps = [
        "//code/utilities/formats/json/extraction:json_extraction_step",
    ],
)

hcp_hdrs_derive(
    name = "json_extraction_step",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "json_extractor",
    interface_deps = [
        "//code/utilities/formats/json/extraction:json_extraction_settings",
        "//code/utilities/types/strings/observers/converting:lib",
    ],
)
