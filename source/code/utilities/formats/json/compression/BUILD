package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "bson_converter",
    interface_deps = [],
)

hcp_hdrs_derive(
    name = "cbor_converter",
    interface_deps = [],
)

hcp_hdrs_derive(
    name = "msgpack_converter",
    interface_deps = [],
)

hcp_hdrs_derive(
    name = "ubjson_converter",
    interface_deps = [],
)

enum_cpp(
    name = "json_compression_format",
    values = [
        "bson",
        "cbor",
        "msgpack",
        "ubjson",
    ],
)

hcp_hdrs_derive(
    name = "json_compressor",
    interface_deps = [
        "//code/utilities/formats/json/compression:bson_converter",
        "//code/utilities/formats/json/compression:cbor_converter",
        "//code/utilities/formats/json/compression:json_compression_format",
        "//code/utilities/formats/json/compression:msgpack_converter",
        "//code/utilities/formats/json/compression:ubjson_converter",
    ],
)
