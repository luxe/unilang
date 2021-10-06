package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "bloom_filter_creator",
    interface_deps = [
        "//code/utilities/deps/external/libbf:lib",
        "//code/utilities/deps/external/bloomfilter_stl_hash:lib",
        "//code/utilities/deps/external/bloomfilter:lib",
        "//code/utilities/deps/external/btl_bloomfilter:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/filesystem/files/deleting:lib",
        "//code/utilities/filesystem/paths:file_content_traverser",
        "//code/utilities/math/gmp:lib",
        "//code/utilities/types/strings/observers/converting:lib",
    ],
)
