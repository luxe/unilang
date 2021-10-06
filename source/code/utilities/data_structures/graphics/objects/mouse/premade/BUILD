package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "standard_mouse",
    interface_deps = [
        "//code/utilities/colors/defaults:color_defaults",
        "//code/utilities/data_structures/graphics/bitmap/premade:crosshair_mouse",
        "//code/utilities/data_structures/graphics/objects/mouse",
        "//code/utilities/graphics/imgui:imgui_type_utility",
    ],
)
