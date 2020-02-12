package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(name = "mouse_button_state",deps=[
])

hcp(name = "mouse_state",deps=[
    "//code/utilities/data_structures/position:position",
    "//code/utilities/peripheral/mouse/state:mouse_button_state",
])

hcp(name="mouse_position_getter", deps = [
"//code/utilities/data_structures/position:position",
"//code/utilities/graphics/imgui:mechanics",
])

hcp(name = "mouse_state_getter",deps=[
    "//code/utilities/peripheral/mouse/state:mouse_state",
    "//code/utilities/graphics/imgui:mechanics",
    "//code/utilities/peripheral/mouse/state:mouse_position_getter",
])