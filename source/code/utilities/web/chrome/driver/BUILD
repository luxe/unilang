package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(
    name = "chrome_driver_selector",
    deps = [
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/strings/observers/columns:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/web/chrome/driver:chrome_driver_selection_settings",
        "//code/utilities/web/chrome/version:chrome_version_getter",
    ],
)

hcp(
    name = "chrome_driver_selection_settings",
    deps = [
    ],
)
