package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "x11_to_opengl_bind_settings",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "x11_to_opengl_binder",
    interface_deps = [
        "//code/utilities/graphics/glx:glx_context_creator",
        "//code/utilities/graphics/glx:glx_data_getter",
        "//code/utilities/graphics/glx:glx_fb_config_creator",
        "//code/utilities/graphics/glx:glx_visual_creator",
        "//code/utilities/graphics/glx:x11_to_opengl_bind_settings",
        "//code/utilities/graphics/glx/data:glx_data",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/deps/external/gl:lib",
        "//code/utilities/deps/external/khr:lib",
    ],
)

hcp_hdrs_derive(
    name = "glx_data_getter",
    interface_deps = [
        "//code/utilities/graphics/glx:glx_context_creator",
        "//code/utilities/graphics/glx:glx_fb_config_creator",
        "//code/utilities/graphics/glx:glx_visual_creator",
        "//code/utilities/graphics/glx:x11_to_opengl_bind_settings",
        "//code/utilities/graphics/glx/data:glx_data",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/deps/external/gl:lib",
        "//code/utilities/deps/external/khr:lib",
    ],
)

hcp_hdrs_derive(
    name = "glx_fb_config_creator",
    interface_deps = [
        "//code/utilities/graphics/glx:x11_to_opengl_bind_settings",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/deps/external/gl:lib",
        "//code/utilities/deps/external/khr:lib",
    ],
)

hcp_hdrs_derive(
    name = "glx_visual_creator",
    interface_deps = [
        "//code/utilities/graphics/glx:x11_to_opengl_bind_settings",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/deps/external/gl:lib",
        "//code/utilities/deps/external/khr:lib",
    ],
)

hcp_hdrs_derive(
    name = "glx_context_creator",
    interface_deps = [
        "//code/utilities/graphics/glx:x11_to_opengl_bind_settings",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/deps/external/gl:lib",
        "//code/utilities/deps/external/khr:lib",
    ],
)
