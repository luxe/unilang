package(default_visibility = ["//visibility:public"])

load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:gtest.bzl", "gtest")

hcp_hdrs_derive(
    name = "zlib_compressor",
    interface_deps = [
        "//code/utilities/deps/external/zlib:lib",
    ],
)

gtest(
    name = "zlib_compressor_test",
    deps = [
        "//code/utilities/formats/compression/zlib:zlib_compressor",
    ],
)
