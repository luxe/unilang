package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "random_hex",
    interface_deps = [
        "//code/utilities/types/char:lib",
        "//code/utilities/types/char:hex_char_index",
        "//code/utilities/deps/stl/random:lib",
        "//code/utilities/types/strings/observers/hex:lib",
        "//code/utilities/types/char:hex_ordering",
    ],
)
