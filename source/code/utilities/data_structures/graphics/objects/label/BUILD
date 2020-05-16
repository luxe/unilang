package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/hcp:hcp_pos.bzl", "hcp_pos")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="label_user_state", deps = [
])


hcp(name="label_settings", deps = [
"//code/utilities/data_structures/color:transparent_rgb_color",
"//code/utilities/data_structures/position:position",
"//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
"//code/utilities/data_structures/graphics/objects/cursor:label_cursor_selection",
"//code/utilities/data_structures/graphics/objects/style:label_styles",
"//code/utilities/data_structures/graphics/objects/label:label_user_state",
"//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
"//code/utilities/data_structures/graphics/objects/cursor:label_cursor",
])

hcp_pos(name="label", deps = [
    "//code/utilities/data_structures/graphics/objects/label:label_settings",
])