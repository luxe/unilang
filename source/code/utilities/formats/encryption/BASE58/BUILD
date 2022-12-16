package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "base58_hasher",
    interface_deps = [
        "//code/utilities/types/strings/observers/hex:lib",
        "//code/utilities/deps/external/libbase58:lib",
        "//code/utilities/deps/external/openssl:lib",
        "//code/utilities/deps/external/secp256k1:lib",
    ],
)
