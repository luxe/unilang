package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "file_upload_settings",
    interface_deps = [
        "//code/utilities/program/wrappers/git/upload:github_upload_settings",
        "//code/utilities/web/dropbox:upload_to_dropbox_strategy",
        "//code/utilities/web/gdrive:gdrive_upload_settings",
    ],
)

hcp_hdrs_derive(
    name = "file_uploader",
    interface_deps = [
        "//code/utilities/output/upload:file_upload_settings",
        "//code/utilities/personal/secret:secret_getter",
        "//code/utilities/program/wrappers/git/upload:github_uploader",
        "//code/utilities/web/dropbox:dropbox_uploader",
        "//code/utilities/web/dropbox:upload_to_dropbox_strategy",
        "//code/utilities/web/gdrive:gdrive_uploader",
    ],
)
