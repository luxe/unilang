package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "game_state",
    interface_deps = [
        "//code/utilities/deps/external/sfml:lib",
        "//code/utilities/data_structures/color:rgb_color",
    ],
)

hcp_hdrs_derive(
    name = "game_state_getter",
    interface_deps = [
        "//code/programs/games/filler/gui/state:game_state",
        "//code/utilities/colors/defaults:color_palettes",
        "//code/utilities/games/filler:grid_generator",
        "//code/utilities/colors/converters:converters",
        "//code/utilities/deps/external/sfml:lib",
    ],
)