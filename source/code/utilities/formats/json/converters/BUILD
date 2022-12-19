package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
        "@nlohmann_json",
    ],
)

hcp_hdrs_derive(
    name = "type_to_json_string",
    interface_deps = [],
)

hcp_hdrs_derive(
    name = "json_file_io",
    interface_deps = [
        "//code/utilities/formats/json/compression:json_compression_format",
        "//code/utilities/formats/json/compression:json_compressor",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/streams/filestreams/write_all:lib",
    ],
)
