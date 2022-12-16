package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
)

hcp_hdrs_derive(
    name = "recurse",
    interface_deps = [
        "//code/utilities/execution:thread_pool_getter",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/deps/stl/filesystem:lib",
    ],
)

cpp_main(
    name = "time_rlstat",
    deps = [":recurse"],
)
