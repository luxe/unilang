package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "red_cursor",
    deps = [
        "//code/utilities/colors/defaults:color_defaults",
        "//code/utilities/data_structures/graphics/objects/cursor:label_cursor",
    ],
)

hcp(
    name = "blue_cursor",
    deps = [
        "//code/utilities/colors/defaults:color_defaults",
        "//code/utilities/data_structures/graphics/objects/cursor:label_cursor",
    ],
)

hcp(
    name = "color_cursor",
    deps = [
        "//code/utilities/colors/defaults:color_defaults",
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/graphics/objects/cursor:label_cursor",
    ],
)
