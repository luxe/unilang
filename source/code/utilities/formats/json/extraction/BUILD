package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "json_extraction_settings",
    deps = [
        "//code/utilities/formats/json/extraction:json_extraction_step",
    ],
)

hcp(
    name = "json_extraction_step",
    deps = [
    ],
)

hcp(
    name = "json_extractor",
    deps = [
        "//code/utilities/formats/json/extraction:json_extraction_settings",
        "//code/utilities/types/strings/observers/converting:lib",
    ],
)
