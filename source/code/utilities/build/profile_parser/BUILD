package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "file_duration_extractor",
    deps = [
        "//code/utilities/build/profile_parser/data:duration_file",
        "//code/utilities/build/profile_parser/data:owned_duration_file",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/formats/json/functions:lib",
        "//code/utilities/build/file_owners_getter:file_owners_getter",
    ],
)