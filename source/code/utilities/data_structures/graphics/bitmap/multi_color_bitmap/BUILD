package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="multi_color_bitmap", deps = [
"//code/utilities/data_structures/graphics/bitmap/pixel:pixel_settings",
])

hcp(name="positioned_multi_color_bitmap", deps = [
    "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:multi_color_bitmap",
    "//code/utilities/data_structures/position:position",
])
