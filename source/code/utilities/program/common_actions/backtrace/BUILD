package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_library(
    name = "backtrace",
    srcs = ["backtrace.cpp"],
    hdrs = ["backtrace.hpp"],
    linkopts = ["-Wl,--wrap,__cxa_throw"],
    deps = [
        "@abseil-cpp//absl/base:core_headers",
        "@abseil-cpp//absl/debugging:stacktrace",
        "@abseil-cpp//absl/debugging:symbolize",
        "@fmt",
    ],
)

cc_library(
    name = "exceptions",
    srcs = ["exceptions.cpp"],
    hdrs = ["exceptions.hpp"],
    deps = [
        "//code/utilities/program/common_actions/backtrace",
        "@abseil-cpp//absl/base:core_headers",
        "@abseil-cpp//absl/debugging:stacktrace",
        "@abseil-cpp//absl/debugging:symbolize",
        "@boost//:algorithm",
        "@fmt",
    ],
)
