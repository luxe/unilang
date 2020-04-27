package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/hcp:hcp_pos.bzl", "hcp_pos")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp(name="slider_state", deps = [
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
])

hcp_and_hcp_pos(name="slider", deps = [
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/slider:slider_state",
])

hcp(name="slider_drawer", deps = [
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/slider:positioned_slider",
    "//code/utilities/graphics/imgui/ui/draw/label/functions:label_drawer",
    "//code/tools/ide/frame/logic:frame_elements",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/peripheral/mouse/state:mouse_state",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
])

