package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "config_monitor",
    deps = [
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/formats/json/functions:lib",
        "//code/utilities/output/diagnostic:diagnostic_printer",
        "//code/utilities/output/diagnostic:diagnostic_settings",
        "//code/utilities/program/inputs/config:config_monitor_settings",
        "//code/utilities/streams/filestreams/read_all:lib",
    ],
)

hcp(
    name = "config_monitor_settings",
    deps = [
    ],
)
