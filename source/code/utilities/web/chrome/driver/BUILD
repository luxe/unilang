package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp_hdrs_derive(
    name = "chrome_driver_selector",
    interface_deps = [
        "//code/utilities/assets:chrome_drivers",
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

hcp_hdrs_derive(
    name = "chrome_driver_selection_settings",
    interface_deps = [
    ],
)
