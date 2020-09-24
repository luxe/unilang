package(default_visibility = ["//visibility:public"])

load("@build_stack_rules_proto//cpp:cpp_proto_library.bzl", "cpp_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "google_api_http",
    srcs = ["google/api/http.proto"],
)

cc_proto_library(
    name = "google_api_http_cc",
    deps = [":google_api_http"],
)

#######################################################
#google/rpc/...
proto_library(
    name = "code",
    srcs = ["google/rpc/code.proto"],
)

cc_proto_library(
    name = "code_cc",
    deps = [":code"],
)

proto_library(
    name = "status",
    srcs = ["google/rpc/status.proto"],
    deps = [
        "@com_google_protobuf//:any_proto",
    ],
)

cc_proto_library(
    name = "status_cc",
    deps = [":status"],
)

proto_library(
    name = "error_details",
    srcs = ["google/rpc/error_details.proto"],
    deps = [
        "@com_google_protobuf//:duration_proto",
    ],
)

cc_proto_library(
    name = "error_details_cc",
    deps = [":error_details"],
)
#######################################################
