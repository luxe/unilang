package(default_visibility = ["//visibility:public"])

load("@build_stack_rules_proto//cpp:cpp_proto_library.bzl", "cpp_proto_library")

proto_library(
    name = "semver",
    srcs = ["build/bazel/semver/semver.proto"],
)

cc_proto_library(
    name = "semver_cc",
    deps = [":semver"],
)

proto_library(
    name = "remote_execution",
    srcs = ["build/bazel/remote/execution/v2/remote_execution.proto"],
    deps = [
        ":semver",
        "@com_google_protobuf//:duration_proto",
        "@com_google_protobuf//:timestamp_proto",
        "@com_google_protobuf//:wrappers_proto",
        "@googleapis//:google_api_annotations_proto",
        "@googleapis//:google_api_http_proto",
        "@googleapis//:google_longrunning_operations_proto",
        "@googleapis//:google_rpc_status_proto",
    ],
)

proto_library(
    name = "remote_asset",
    srcs = ["build/bazel/remote/asset/v1/remote_asset.proto"],
)

cc_proto_library(
    name = "remote_asset_cc",
    deps = [":remote_asset"],
)
