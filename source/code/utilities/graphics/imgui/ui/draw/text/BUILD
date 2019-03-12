package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")


hcp(name="text_to_bitmap", deps = [
"//code/utilities/graphics/imgui/ui/draw/full_color_bitmap:full_color_bitmap",
"//code/utilities/graphics/imgui/ui/draw/full_color_bitmap:full_color_bitmap_drawer",
"//code/utilities/types/char:lib",
"//code/utilities/bdf/settings:character_segment",
])