package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "@nlohmann_json",
    ],
)

hcp(name = "type_to_json_string",deps = [])

hcp(name = "json_file_io",deps = [
    "//code/utilities/formats/json/compression:json_compression_format",
    "//code/utilities/formats/json/compression:json_compressor",
    "//code/utilities/streams/filestreams/read_all:lib",
    "//code/utilities/streams/filestreams/write_all:lib",
    "//code/utilities/formats/json/converters:type_to_json_string",
])
