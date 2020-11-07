package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "bson_converter",deps = [])
hcp(name = "cbor_converter",deps = [])
hcp(name = "msgpack_converter",deps = [])
hcp(name = "ubjson_converter",deps = [])

enum_cpp(
    name = "json_compression_format",
    values = [
        "bson",
        "cbor",
        "msgpack",
        "ubjson",
    ],
)

hcp(name = "json_compressor",
deps = [
    "//code/utilities/formats/json/compression:bson_converter",
    "//code/utilities/formats/json/compression:cbor_converter",
    "//code/utilities/formats/json/compression:msgpack_converter",
    "//code/utilities/formats/json/compression:ubjson_converter",
    "//code/utilities/formats/json/compression:json_compression_format",
])