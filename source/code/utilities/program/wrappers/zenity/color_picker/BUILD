package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "color_picker",
    deps = [
        "//code/utilities/colors:converters",
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/call:thread_caller",
        "//code/utilities/program/wrappers/zenity/color_picker:color_picker_settings",
    ],
)

hcp(
    name = "color_picker_settings",
    deps = [
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/program/call:lib",
    ],
)
