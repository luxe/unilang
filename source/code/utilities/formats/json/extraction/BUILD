package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "json_extraction_settings", deps = [
    "//code/utilities/formats/json/extraction:json_extraction_step"
])

hcp(name = "json_extraction_step", deps = [
])

hcp(name = "json_extractor", deps = [
    "//code/utilities/formats/json/extraction:json_extraction_settings",
    "//code/utilities/types/strings/observers/converting:lib",
])