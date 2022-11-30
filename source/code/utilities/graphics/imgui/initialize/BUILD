package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "opengl_initializer",
    deps = [
        "@GL",
        "//code/utilities/deps/external/imgui:lib",
    ],
)

hcp(
    name = "imgui_state",
    deps = [
        "//code/utilities/deps/external/imgui:lib",
    ],
)

hcp(
    name = "imgui_initializer",
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/graphics/imgui/initialize:imgui_state",
        "//code/utilities/graphics/imgui/initialize:opengl_initializer",
        "//code/utilities/graphics/opengl/loader:opengl_loader",
        "//code/utilities/graphics/sdl:sdl_init_settings",
        "//code/utilities/graphics/sdl:sdl_initializer",
        "//code/utilities/graphics/sdl:sdl_swap_interval_setter",
        "//code/utilities/graphics/sdl:sdl_window_creator",
        "//code/utilities/deps/external/imgui:lib",
    ],
)
