package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

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
        "//code/utilities/program/wrappers/zenity/file_selector:file_action"
    ],
)

