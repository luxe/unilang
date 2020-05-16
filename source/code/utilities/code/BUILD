package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="concept_tree_getter",deps = [
    "//code/utilities/data_structures/tree/generic:string_tree",
    "@tree//:tree",
])

hcp(name="concept_tree_to_image",deps = [
    "//code/utilities/data_structures/tree/generic:string_tree",
    "//code/utilities/code:concept_tree_getter",
    "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:positioned_button_face_tree",
    "//code/utilities/data_structures/graphics/bitmap/premade:tree_button",
    "//code/utilities/fonts/bdf/complete/unilang:unilang_character_maps",
    "//code/utilities/data_structures/graphics/objects:frame_elements",
    "//code/utilities/peripheral/mouse/state:mouse_state",
    "//code/utilities/peripheral/pc:pc_input_state",
    "//code/utilities/data_structures/graphics/objects/functions:button_tree_label_drawer",
    "//code/utilities/graphics/cairo/render:cairo_render_settings",
    "//code/utilities/graphics/cairo/render:frame_renderer",
    "//code/utilities/data_structures/graphics/objects/style:default_label_styles",
    "//code/utilities/personal/hosting:hosting_repo",
    "//code/utilities/filesystem/paths:lib",
    "@tree//:tree",
])