package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "cursor",
    interface_deps = [
        "//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
    ],
)

hcp_hdrs_derive(
    name = "label_cursor",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/cursor/data:cursor",
    ],
)

hcp_hdrs_derive(
    name = "label_cursor_selection",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/cursor/data:label_cursor",
        "//code/utilities/data_structures/position",
    ],
)

hcp_hdrs_derive(
    name = "cursor_ability",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "default_cursor_ability",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/cursor/data:cursor_ability",
    ],
)

hcp_hdrs_derive(
    name = "controlled_label_cursor_selections",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/cursor/data:cursor_ability",
        "//code/utilities/data_structures/graphics/objects/cursor/data:label_cursor_selection",
    ],
)
