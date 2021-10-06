package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "metrics_publisher",
    deps = [
        "//code/utilities/data_structures/endpoint",
        "//code/utilities/web/statsd:statsd_nc_poster",
    ],
)
