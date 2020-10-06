package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "server_settings",
)

hcp(
    name = "server",
    deps = [
        "@com_github_grpc_grpc//:grpc++_reflection",
        "@remote_apis//:remote_execution_cc_proto",
        "//code/utilities/formats/serialization:protobuf",
        "//code/tools/repo_tools/remote_execution/server:server_settings",
        "//code/utilities/remote_execution/services:grpc_glue",
        "@semver",
        "//code/utilities/output/logging:debug_spdlog",
        "//code/tools/repo_tools/remote_execution/server/capabilities:capabilities_endpoint",
        "//code/tools/repo_tools/remote_execution/server/action_cache:action_cache_endpoint",
])

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "@com_github_grpc_grpc//:grpc++",
        "@com_github_grpc_grpc//:grpc++_reflection",
        "@remote_apis//:remote_execution_cc_proto",
        "//code/utilities/formats/serialization:protobuf",
        "//code/tools/repo_tools/remote_execution/server:server_settings",
        "//code/tools/repo_tools/remote_execution/server:server",
        "//code/utilities/remote_execution/services:grpc_glue",
    ],
)
