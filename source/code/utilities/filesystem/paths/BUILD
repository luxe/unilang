package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/program/call:lib",
        "@boost//:filesystem",
        "@boost//:range",
    ],
)

hcp(
    name = "path_getter",
    deps = [
        "//code/utilities/filesystem/paths:lib",
    ],
)

hcp_hdrs_derive(
    name = "file_content_traverser",
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

cpp_main(
    name = "path_to_desktop",
    deps = ["//code/utilities/filesystem/paths:lib"],
)

cpp_main(
    name = "current_path",
    deps = ["//code/utilities/filesystem/paths:lib"],
)

cpp_main(
    name = "bazel_workspace_directory",
    deps = ["//code/utilities/filesystem/paths:lib"],
)

cpp_main(
    name = "bazel_derived_root",
    deps = ["//code/utilities/filesystem/paths:lib"],
)
