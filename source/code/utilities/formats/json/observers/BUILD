package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "observers",
    interface_deps = [
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
    ],
)
