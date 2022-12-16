package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "get_dir_size",
    interface_deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
    ],
)

hcp_hdrs_derive(
    name = "get_total_file_count",
    interface_deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
    ],
)

hcp_hdrs_derive(
    name = "file_line_counter",
    interface_deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
    ],
)
