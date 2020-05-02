package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="label_cursor_selection", deps = [
"//code/utilities/data_structures/position:position",
"//code/utilities/graphics/imgui/ui/draw/label/cursor:label_cursor",
])

hcp(name="label_cursor_mover", deps = [
"//code/utilities/fonts/bdf/settings:character_segment",
"//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
"//code/utilities/graphics/imgui/ui/draw/label/cursor:label_cursor_selection",
"//code/utilities/data_structures/graphics/text:str_to_bdf_segments",
"//code/utilities/fonts/bdf/character_maps:character_maps",
])

hcp(name="cursor",deps = [
"//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
])

hcp(name="label_cursor", deps = [
    "//code/utilities/graphics/imgui/ui/draw/label/cursor:cursor"
])