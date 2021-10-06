package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "protocol_buffer_settings",
    deps = [
        "//code/utilities/linguistics/computer/frontends/protobuf/settings/enum:protocol_buffer_enum_settings",
        "//code/utilities/linguistics/computer/frontends/protobuf/settings/import:protocol_buffer_import_settings",
        "//code/utilities/linguistics/computer/frontends/protobuf/settings/message:protocol_buffer_message_settings",
        "//code/utilities/linguistics/computer/frontends/protobuf/settings/tag:protocol_buffer_tag_settings",
        "//code/utilities/linguistics/computer/frontends/protobuf/settings/version:protocol_buffer_version_settings",
    ],
)
