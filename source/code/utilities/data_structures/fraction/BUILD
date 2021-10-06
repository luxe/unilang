package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(name = "fraction")

hcp_hdrs_derive(
    name = "fraction_parser",
    interface_deps = [
        "//code/utilities/data_structures/fraction",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
    ],
)

hcp_hdrs_derive(
    name = "gmp_fraction",
    interface_deps = [
        "//code/utilities/math/gmp:lib",
    ],
)
