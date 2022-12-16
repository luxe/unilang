package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "gdrive_uploader",
    interface_deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/web/gdrive:gdrive_upload_settings",
    ],
)

hcp_hdrs_derive(
    name = "gdrive_upload_settings",
    interface_deps = [
    ],
)
