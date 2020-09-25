package(default_visibility = ["//visibility:public"])

#load("@build_stack_rules_proto//cpp:cpp_proto_library.bzl", "cpp_proto_library")
load("@bazel_remote_apis_imports//:imports.bzl", "cc_grpc_library", "go_library", "go_proto_library", "java_proto_library")

proto_library(
    name = "semver_proto",
    srcs = ["build/bazel/semver/semver.proto"],
)

# cc_proto_library(
#     name = "semver_cc_proto",
#     deps = [":semver"],
# )

cc_grpc_library(
    name = "semver_cc_proto",
    srcs = ["build/bazel/semver/semver.proto"],
    proto_only = False,
    use_external = False,
    well_known_protos = True,
    deps = [],
)

# proto_library(
#     name = "remote_asset_proto",
#     srcs = ["build/bazel/remote/asset/v1/remote_asset.proto"],
#     deps = [
#         ":remote_execution_proto",
#         "@com_google_protobuf//:duration_proto",
#         "@com_google_protobuf//:timestamp_proto",
#         "@googleapis//google/api:annotations_proto",
#         "@googleapis//google/api:http_proto",
#         "@googleapis//google/rpc:status_proto",
#     ],
# )

# cc_grpc_library(
#     name = "remote_asset_cc_proto",
#     srcs = ["build/bazel/remote/asset/v1/remote_asset.proto"],
#     proto_only = False,
#     use_external = False,
#     well_known_protos = True,
#     deps = [
#         "//build/bazel/remote/execution/v2:remote_execution_cc_proto",
#         "@googleapis//:google_api_annotations_cc_proto",
#         "@googleapis//:google_api_http_cc_proto",
#         "@googleapis//:google_rpc_status_cc_proto",
#     ],
# )

# proto_library(
#     name = "remote_execution_proto",
#     srcs = ["build/bazel/remote/execution/v2/remote_execution.proto"],
#     deps = [
#         ":semver_proto",
#         "@com_google_protobuf//:duration_proto",
#         "@com_google_protobuf//:timestamp_proto",
#         "@com_google_protobuf//:wrappers_proto",
#         "@googleapis//google/api:annotations_proto",
#         "@googleapis//google/api:http_proto",
#         "@googleapis//google/longrunning:operations_proto",
#         "@googleapis//google/rpc:status_proto",
#     ],
# )

# proto_library(
#     name = "remote_asset",
#     srcs = ["build/bazel/remote/asset/v1/remote_asset.proto"],
# )

# cc_proto_library(
#     name = "remote_asset_cc",
#     deps = [":remote_asset"],
# )
