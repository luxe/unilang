package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/hcp:hcp_and_hcp_pos_hdrs_derive.bzl", "hcp_and_hcp_pos_hdrs_derive")

cpp_object(
    name = "stb_image",
    deps = [
        "//code/utilities/deps/external/stb_image:lib",
    ],
)

hcp_hdrs_derive(
    name = "stb_image_set_settings",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "texture_loader",
    interface_deps = [
        "//code/utilities/graphics/opengl/loader:opengl_loaders",
        "//code/utilities/image:stb_image",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/deps/external/imgui:lib",
        "//code/utilities/deps/external/khr:lib",
    ],
)

hcp_hdrs_derive(
    name = "stb_image_setter",
    interface_deps = [
        "//code/utilities/data_structures/graphics/image:positioned_image_data",
        "//code/utilities/image:stb_image",
        "//code/utilities/image:stb_image_set_settings",
        "//code/utilities/image:texture_loader",
        "//code/utilities/streams/filestreams:lib",
    ],
)

hcp_hdrs_derive(
    name = "stb_animated_image_setter",
    interface_deps = [
        "//code/utilities/data_structures/graphics/image:positioned_animated_image_data",
        "//code/utilities/image:stb_image",
        "//code/utilities/image:stb_image_set_settings",
        "//code/utilities/image:texture_loader",
        "//code/utilities/streams/filestreams:lib",
    ],
)

hcp_hdrs_derive(
    name = "data_uri_getter",
    interface_deps = [
        "//code/utilities/program/call:lib",
    ],
)
