package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
)

hcp(
    name = "recurse",
    deps = [
        "//code/utilities/execution:thread_pool_getter",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
    ],
)

cpp_main(
    name = "time_rlstat",
    deps = [":recurse"],
)
