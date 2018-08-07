package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp( name = "protocol_buffer_settings",
deps = [
"//code/transcompilers/unilang/options/language-specific/protocol_buffer_settings/import:protocol_buffer_import_settings",
"//code/transcompilers/unilang/options/language-specific/protocol_buffer_settings/version:protocol_buffer_version_settings",
"//code/transcompilers/unilang/options/language-specific/protocol_buffer_settings/message:protocol_buffer_message_settings",
"//code/transcompilers/unilang/options/language-specific/protocol_buffer_settings/tag:protocol_buffer_tag_settings",
"//code/transcompilers/unilang/options/language-specific/protocol_buffer_settings/enum:protocol_buffer_enum_settings",
])