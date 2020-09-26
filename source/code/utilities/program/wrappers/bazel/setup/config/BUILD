package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "bazel_config_settings",
    deps = [
    ],
)

hcp(
    name = "bazel_config_deriver",
    deps = [
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/program/wrappers/bazel/setup/config:bazel_config_settings",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/strings/observers/other:lib",
    ],
)
