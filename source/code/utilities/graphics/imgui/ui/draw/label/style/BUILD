package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="label_style", deps = [
    "//code/utilities/data_structures/color:transparent_rgb_color",
    "//code/utilities/data_structures/shapes/rectangle:rectangle_shade_colors",
    "//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
    "//code/utilities/graphics/imgui/ui/draw/label/style:label_width_style",
])

hcp(name="label_styles", deps = [
    "//code/utilities/graphics/imgui/ui/draw/label/style:label_style",
])

hcp(name="label_width_style", deps = [
"//code/utilities/graphics/imgui/ui/draw/bitmap/pixel:pixel_slider",
])


hcp(name="label_style_chooser", deps = [
"//code/utilities/graphics/imgui/ui/draw/label:label_settings",
])
