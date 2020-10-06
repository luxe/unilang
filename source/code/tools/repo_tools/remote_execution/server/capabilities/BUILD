package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")


hcp(
    name = "capabilities_endpoint",
    deps = [
        "@com_github_grpc_grpc//:grpc++_reflection",
        "@remote_apis//:remote_execution_cc_proto",
        "//code/utilities/formats/serialization:protobuf",
        "//code/tools/repo_tools/remote_execution/server:server_settings",
        "//code/utilities/remote_execution/services:grpc_glue",
        "//code/tools/repo_tools/remote_execution/server/capabilities:server_capabilities_getter",
        "@semver",
        "//code/utilities/output/logging:debug_spdlog",
])

hcp(
    name = "server_capabilities_getter",
    deps = [
        "@com_github_grpc_grpc//:grpc++_reflection",
        "@remote_apis//:remote_execution_cc_proto",
        "//code/utilities/formats/serialization:protobuf",
        "//code/tools/repo_tools/remote_execution/server:server_settings",
        "//code/utilities/remote_execution/services:grpc_glue",
        "@semver",
])