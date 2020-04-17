package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="label_cursor_selection", deps = [
"//code/utilities/data_structures/position:position",
"//code/tools/ide/settings:label_cursor",
])

hcp(name="label_cursor_mover", deps = [
"//code/utilities/fonts/bdf/settings:character_segment",
"//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
"//code/utilities/graphics/imgui/ui/draw/label/cursor:label_cursor_selection",
"//code/utilities/graphics/imgui/ui/draw/text:str_to_bdf_segments",
])