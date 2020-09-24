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

proto_library(
    name = "status",
    srcs = ["google/rpc/status.proto"],
    deps = [
        "@com_google_protobuf//:any_proto",
    ],
)
