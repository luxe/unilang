package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="label_settings", deps = [
"//code/utilities/data_structures/color:transparent_rgb_color",
"//code/utilities/data_structures/position:position",
"//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
"//code/utilities/graphics/imgui/ui/draw/label/cursor:label_cursor_selection",
"//code/utilities/graphics/imgui/ui/draw/label/style:label_styles",
"//code/utilities/graphics/imgui/ui/draw/label:label_user_state",
])

hcp(name="label_user_state", deps = [
])

hcp(name="label_face", deps = [
    "//code/utilities/graphics/imgui/ui/draw/label:label_settings",
])

hcp(name="positioned_label", deps = [
    "//code/utilities/data_structures/position:position",
    "//code/utilities/graphics/imgui/ui/draw/label:label_settings",
])

hcp(name="positioned_faced_label", deps = [
    "//code/utilities/data_structures/position:position",
    "//code/utilities/graphics/imgui/ui/draw/label:label_face",
])
