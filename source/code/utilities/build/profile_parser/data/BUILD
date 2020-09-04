package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "duration_file",
    deps = [],
)

hcp(
    name = "owned_duration_file",
    deps = [
        "//code/utilities/build/profile_parser/data:duration_file",
    ],
)

hcp(
    name = "flat_owned_duration_file",
    deps = [
        "//code/utilities/build/profile_parser/data:duration_file",
    ],
)
