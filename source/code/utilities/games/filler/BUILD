package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")


hcp_hdrs_derive(
    name = "grid_generator",
    interface_deps = [
        "//code/utilities/language_basic/std_hackery:std_aliases",
        "//code/utilities/random:lib",
        "//code/utilities/types/vectors/observers:lib",
    ]
)