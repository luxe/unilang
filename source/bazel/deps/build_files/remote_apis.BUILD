#These rules were copied from:  
#https://github.com/bazelbuild/remote-apis
#They use some googleapis targets which were also taken from that repo
package(default_visibility = ["//visibility:public"])
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")

proto_library(
    name = "semver_proto",
    srcs = ["build/bazel/semver/semver.proto"],
)

cc_grpc_library(
    name = "semver_cc_proto",
    srcs = ["build/bazel/semver/semver.proto"],
    proto_only = False,
    use_external = False,
    well_known_protos = True,
    deps = [],
)

proto_library(
    name = "remote_logstream_proto",
    srcs = ["build/bazel/remote/logstream/v1/remote_logstream.proto"],
    deps = [
    ],
)

cc_grpc_library(
    name = "remote_logstream_cc_proto",
    srcs = ["build/bazel/remote/logstream/v1/remote_logstream.proto"],
    proto_only = False,
    use_external = False,
    well_known_protos = True,
    deps = [
    ],
)

proto_library(
    name = "remote_execution_proto",
    srcs = ["build/bazel/remote/execution/v2/remote_execution.proto"],
    deps = [
        ":semver_proto",
        "@com_google_protobuf//:duration_proto",
        "@com_google_protobuf//:timestamp_proto",
        "@com_google_protobuf//:wrappers_proto",
        "@googleapis//:google_api_annotations_proto",
        "@googleapis//:google_api_http_proto",
        "@googleapis//:google_longrunning_operations_proto",
        "@googleapis//:google_rpc_status_proto",
    ],
)

cc_grpc_library(
    name = "remote_execution_cc_proto",
    srcs = ["build/bazel/remote/execution/v2/remote_execution.proto"],
    proto_only = False,
    use_external = False,
    well_known_protos = True,
    deps = [
        ":semver_cc_proto",
        "@googleapis//:google_api_annotations_cc_proto",
        "@googleapis//:google_api_http_cc_proto",
        "@googleapis//:google_longrunning_operations_cc_proto",
        "@googleapis//:google_rpc_status_cc_proto",
    ],
)

proto_library(
    name = "remote_asset_proto",
    srcs = ["build/bazel/remote/asset/v1/remote_asset.proto"],
    deps = [
        ":remote_execution_proto",
        "@com_google_protobuf//:duration_proto",
        "@com_google_protobuf//:timestamp_proto",
        "@googleapis//:google_api_annotations_proto",
        "@googleapis//:google_api_http_proto",
        "@googleapis//:google_rpc_status_proto",
    ],
)

cc_grpc_library(
    name = "remote_asset_cc_proto",
    srcs = ["build/bazel/remote/asset/v1/remote_asset.proto"],
    proto_only = False,
    use_external = False,
    well_known_protos = True,
    deps = [
        ":remote_execution_cc_proto",
        "@googleapis//:google_api_annotations_cc_proto",
        "@googleapis//:google_api_http_cc_proto",
        "@googleapis//:google_rpc_status_cc_proto",
    ],
)