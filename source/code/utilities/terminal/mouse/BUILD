package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "mouse_binded_gama_slider",
    deps = [
        "//code/utilities/data_structures:optional_two_d_coordinate_dimension",
        "//code/utilities/peripheral/screen/good_bad:gama_slider",
    ],
)

hcp(
    name = "mouse_terminal_settings",
    deps = [
        "//code/utilities/terminal/mouse:mouse_binded_gama_slider",
    ],
)

hcp(
    name = "mouse_terminal_changer",
    deps = [
        "//code/utilities/colors/converters:hsv_to_rgb_converter",
        "//code/utilities/colors/transformers:screen_position_to_rgb",
        "//code/utilities/data_structures/color:hsv_color",
        "//code/utilities/data_structures/position",
        "//code/utilities/math",
        "//code/utilities/program/call:lib",
        "//code/utilities/terminal:terminal_background_changer",
        "//code/utilities/terminal/mouse:mouse_terminal_settings",
    ],
)
