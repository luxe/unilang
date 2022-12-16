package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(name = "sdl_window_settings")

enum_cpp(
    name = "sdl_swap_interval",
    values =
        [
            "immediate",
            "synchronized_vertical_retrace",
            "adaptive_vsync",
        ],
)

hcp_hdrs_derive(
    name = "sdl_init_settings",
    interface_deps = [
        "//code/utilities/graphics/sdl:sdl_swap_interval",
        "//code/utilities/graphics/sdl:sdl_window_settings",
    ],
)

hcp_hdrs_derive(
    name = "standard_sdl_init_settings",
    interface_deps = [
        "//code/utilities/graphics/sdl:sdl_init_settings",
    ],
)

hcp_hdrs_derive(
    name = "sdl_window_creator",
    interface_deps = [
        "//code/utilities/graphics/sdl:sdl_init_settings",
        "//code/utilities/deps/external/sdl2:lib",
    ],
)

hcp_hdrs_derive(
    name = "sdl_initializer",
    interface_deps = [
        "//code/utilities/graphics/sdl:sdl_init_settings",
        "//code/utilities/deps/external/sdl2:lib",
    ],
)

hcp_hdrs_derive(
    name = "sdl_swap_interval_setter",
    interface_deps = [
        "//code/utilities/graphics/sdl:sdl_swap_interval",
        "//code/utilities/deps/external/sdl2:lib",
    ],
)

hcp_hdrs_derive(
    name = "sdl_fullscreener",
    interface_deps = [
        "//code/utilities/graphics/sdl:sdl_window_settings",
        "//code/utilities/deps/external/sdl2:lib",
    ],
)
