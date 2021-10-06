package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "element_progress_traverse",
    interface_deps = [
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/filesystem/files/size:file_line_counter",
        "//code/utilities/data_structures/fraction:gmp_fraction",
        "//code/utilities/deps/stl/fstream:lib",
        "//code/utilities/deps/external/indicators:lib",
        "//code/utilities/types/strings/observers/converting:lib",
    ],
)
