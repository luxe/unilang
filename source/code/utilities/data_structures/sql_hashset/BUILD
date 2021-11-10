package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "sql_hashset_settings",
    interface_deps = [
        "//code/utilities/data_structures:persistence",
    ],
)

hcp_hdrs_derive(
    name = "sql_hashset",
    interface_deps = [
        "//code/utilities/data_structures/sql_hashset:sql_hashset_settings",
        "//code/utilities/random/files:random_files",
        "//code/utilities/deps/external/sqlite_modern_cpp:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/filesystem/files/deleting:lib",
        "//code/utilities/filesystem/paths:file_content_traverser",
        "//code/utilities/math/gmp:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
    ],
)
