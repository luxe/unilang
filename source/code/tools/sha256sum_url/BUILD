package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

#build main and deploy stuff
cc_binary(
    name = "sha256sum_url",
    srcs = ["sha256sum_url.cpp"],
    deps = [
        "//code/utilities/formats/compression:lib",
    ],
)
