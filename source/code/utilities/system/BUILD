package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "installed_programs_checker",
    interface_deps = [
        "//code/utilities/system:check_installed_program_settings",
        "//code/utilities/system:lib",
    ],
)

hcp_hdrs_derive(
    name = "check_installed_program_settings",
    interface_deps = [
    ],
)

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = ["//code/utilities/program/call:lib"],
)
