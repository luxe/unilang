package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "dogecoin_latest_block_getter",
    interface_deps = [
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/wget:wget_downloader",
        "//code/utilities/system:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/assets:dogecoin_tools",
    ],
)

hcp_hdrs_derive(
    name = "dogecoin_block_getter",
    interface_deps = [
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/wget:wget_downloader",
        "//code/utilities/system:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/assets:dogecoin_tools",
    ],
)

hcp_hdrs_derive(
    name = "dogecoin_get_block_by_height",
    interface_deps = [
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/wget:wget_downloader",
        "//code/utilities/system:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/assets:dogecoin_tools",
    ],
)

hcp_hdrs_derive(
    name = "ensure_dogecoind_is_running",
    interface_deps = [
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/wget:wget_downloader",
        "//code/utilities/system:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/assets:dogecoin_tools",
        "//code/utilities/time/sleeping:lib",
        "//code/utilities/program/processes:lib",
    ],
)