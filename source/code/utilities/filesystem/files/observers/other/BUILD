package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

hcp_hdrs_derive(
    name = "ldd_results",
    interface_deps = [
        "//code/utilities/filesystem/files/observers/other:ldd_entry",
    ],
)

hcp_hdrs_derive(
    name = "ldd_entry",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "file_and_ldd_results",
    interface_deps = [
        "//code/utilities/filesystem/files/observers/other:ldd_results",
    ],
)

hcp_hdrs_derive(
    name = "ldd_results_getter",
    interface_deps = [
        "//code/utilities/filesystem/files/observers/other:file_and_ldd_results",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp_hdrs_derive(
    name = "recursive_ldd_results_getter",
    interface_deps = [
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/files/observers/other:file_and_ldd_results",
        "//code/utilities/filesystem/files/observers/other:ldd_results_getter",
        "//code/utilities/filesystem/files/observers/other:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
    ],
)

hcp_hdrs_derive(
    name = "recursive_ldd_scan_printer",
    interface_deps = [
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/files/observers/other:recursive_ldd_results_getter",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/wrappers/bazel:bazel_runner",
        "//code/utilities/program/wrappers/bazel/query:bazel_aquery_runner",
        "//code/utilities/types/strings/observers/other:lib",
    ],
)
