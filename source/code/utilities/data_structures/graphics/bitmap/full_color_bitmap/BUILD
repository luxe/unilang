package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="full_color_bitmap", deps = [
"//code/utilities/data_structures/color:transparent_rgb_color",
"//code/utilities/data_structures/position:position",
])

hcp(name="positioned_full_color_bitmap", deps = [
"//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:full_color_bitmap",
"//code/utilities/data_structures/position:position",
])
