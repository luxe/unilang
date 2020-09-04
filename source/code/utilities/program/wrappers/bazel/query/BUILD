package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "bazel_query_runner",
    deps = [
        "//code/utilities/formats/json/functions:lib",
        "//code/utilities/formats/serialization:protobuf",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/inputs/flags:flag_util",
        "//code/utilities/program/inputs/flags/data:flags",
        "//code/utilities/program/wrappers/bazel:run_environment",
        "//code/utilities/program/wrappers/bazel/query:query_deps_flags",
        "//code/utilities/random:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "@bazel//:spawn_proto_cpp",
    ],
)

hcp(
    name = "query_deps_flags",
    deps = [
    ],
)
