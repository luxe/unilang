package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "protocol_buffer_settings",
    deps = [
        "//code/tools/transcompilers/old_unilang/options/language-specific/protocol_buffer_settings/enum:protocol_buffer_enum_settings",
        "//code/tools/transcompilers/old_unilang/options/language-specific/protocol_buffer_settings/import:protocol_buffer_import_settings",
        "//code/tools/transcompilers/old_unilang/options/language-specific/protocol_buffer_settings/message:protocol_buffer_message_settings",
        "//code/tools/transcompilers/old_unilang/options/language-specific/protocol_buffer_settings/tag:protocol_buffer_tag_settings",
        "//code/tools/transcompilers/old_unilang/options/language-specific/protocol_buffer_settings/version:protocol_buffer_version_settings",
    ],
)