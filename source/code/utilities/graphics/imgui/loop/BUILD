package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "mechanics",
    deps = [
        "@imgui//:imgui_sdl_opengl3",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/graphics/sdl:sdl_init_settings",
        "//code/utilities/graphics/sdl:sdl_window_creator",
        #"//code/utilities/graphics/sfml:game_loop",
        "//code/utilities/graphics/sdl:sdl_initializer",
        "//code/utilities/graphics/sdl:sdl_swap_interval_setter",
        "//code/utilities/graphics/opengl/loader:opengl_loader",
        "//code/utilities/graphics/imgui/initialize:opengl_initializer",
        "//code/utilities/graphics/imgui/initialize:imgui_initializer",
        "//code/utilities/graphics/imgui/loop:event_poller",
        "@GL",
    ],
)

hcp(
    name = "event_poller",
    deps = [
        "@imgui//:imgui_sdl_opengl3",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/graphics/sdl:sdl_init_settings",
        "//code/utilities/graphics/sdl:sdl_window_creator",
        "@GL",
    ],
)