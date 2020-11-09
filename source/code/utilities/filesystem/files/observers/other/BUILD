package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/hcp:hcp.bzl", "hcp")

hcp(
    name = "ldd_results",
    deps = [
        "//code/utilities/filesystem/files/observers/other:ldd_entry",
    ],
)

hcp(
    name = "ldd_entry",
    deps = [
    ],
)

hcp(
    name = "file_and_ldd_results",
    deps = [
        "//code/utilities/filesystem/files/observers/other:ldd_results",
    ],
)

hcp(
    name = "ldd_results_getter",
    deps = [
        "//code/utilities/filesystem/files/observers/other:file_and_ldd_results",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "recursive_ldd_results_getter",
    deps = [
        "//code/tools/repo_tools/shared_object_trace:file_and_type",
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
