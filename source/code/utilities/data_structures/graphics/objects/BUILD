package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "frame_elements",
    deps = [
        "//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:positioned_full_color_bitmap",
    ],
)
