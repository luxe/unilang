package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "bazel_sync_logger",
    deps = [
        "//code/utilities/build/build_repo_establisher:build_repo_settings",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/program/wrappers/bazel:bazel_runner",
        "@bazel//:workspace_log_proto_cpp",
    ],
)