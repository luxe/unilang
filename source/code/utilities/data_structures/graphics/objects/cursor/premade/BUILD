package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "red_cursor",
    interface_deps = [
        "//code/utilities/colors/defaults:color_defaults",
        "//code/utilities/data_structures/graphics/objects/cursor/data:label_cursor",
        "//code/utilities/data_structures/graphics/objects/cursor/premade:color_cursor",
    ],
)

hcp_hdrs_derive(
    name = "blue_cursor",
    interface_deps = [
        "//code/utilities/colors/defaults:color_defaults",
        "//code/utilities/data_structures/graphics/objects/cursor/data:label_cursor",
        "//code/utilities/data_structures/graphics/objects/cursor/premade:color_cursor",
    ],
)

hcp_hdrs_derive(
    name = "color_cursor",
    interface_deps = [
        "//code/utilities/colors/defaults:color_defaults",
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/graphics/objects/cursor/data:label_cursor",
    ],
)
