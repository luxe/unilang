package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "cquery_results",
    deps = [
        "//code/utilities/deps/external/bazel_analysis_proto:lib",
        "//code/utilities/deps/external/bazel_spawn_proto:lib",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/formats/serialization:protobuf",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/call/process_spawn/timed:timed_process_results",
        "//code/utilities/program/inputs/flags:flag_util",
        "//code/utilities/program/inputs/flags/data:flags",
        "//code/utilities/program/wrappers/bazel:run_environment",
        "//code/utilities/program/wrappers/bazel/query:query_deps_flags",
    ],
)

hcp(
    name = "aquery_results",
    deps = [
        "//code/utilities/deps/external/bazel_analysis_proto:lib",
        "//code/utilities/deps/external/bazel_spawn_proto:lib",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/formats/serialization:protobuf",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/call/process_spawn/timed:timed_process_results",
        "//code/utilities/program/inputs/flags:flag_util",
        "//code/utilities/program/inputs/flags/data:flags",
        "//code/utilities/program/wrappers/bazel:run_environment",
        "//code/utilities/program/wrappers/bazel/query:query_deps_flags",
    ],
)
