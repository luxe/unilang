package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "dropbox_uploader",
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/web/dropbox:dropbox_upload_settings",
        "@curl",
    ],
)

cc_binary(
    name = "upload",
    srcs = ["upload_to_dropbox.cpp"],
    deps = [
        "//code/utilities/personal/secret:secret_getter",
        "//code/utilities/web/dropbox:dropbox_upload_settings",
        "//code/utilities/web/dropbox:dropbox_uploader",
    ],
)

hcp(
    name = "dropbox_upload_settings",
    deps = [
        "//code/utilities/web/dropbox:upload_to_dropbox_strategy",
    ],
)

enum_cpp(
    name = "upload_to_dropbox_strategy",
    values =
        [
            "curl_command",
            "curl_lib",
        ],
)
