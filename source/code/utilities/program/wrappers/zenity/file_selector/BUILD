package(default_visibility = ["//visibility:public"])

load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

enum_cpp(
    name = "file_action",
    values = [
        "select",
        "save",
    ],
)

hcp(
    name = "file_selection_settings",
    deps = [
        "//code/utilities/program/wrappers/zenity/file_selector:file_action",
    ],
)

hcp(
    name = "file_selector",
    deps = [
        "//code/utilities/colors/converters",
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/call:thread_caller",
        "//code/utilities/program/wrappers/zenity/file_selector:file_selection_settings",
    ],
)