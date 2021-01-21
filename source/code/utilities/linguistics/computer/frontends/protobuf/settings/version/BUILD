package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object("protocol_buffer_version_number")

hcp(
    name = "protocol_buffer_version_settings",
    deps = [
        "//code/utilities/linguistics/computer/frontends/protobuf/settings/version:protocol_buffer_version_number",
    ],
)
