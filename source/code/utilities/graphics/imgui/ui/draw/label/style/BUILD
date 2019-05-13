package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="label_style", deps = [
    "//code/utilities/graphics/imgui/ui/draw:color",
    "//code/utilities/graphics/imgui/ui/draw/rectangle:rectangle_settings",
    "//code/utilities/graphics/imgui/ui/draw/label/style:label_width_style",
])

hcp(name="label_styles", deps = [
    "//code/utilities/graphics/imgui/ui/draw/label/style:label_style",
])

hcp(name="label_width_style", deps = [
"//code/utilities/graphics/imgui/ui/draw/bitmap/pixel:pixel_slider",
])
