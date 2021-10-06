package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/tree_hcp:string_tree_getter.bzl", "string_tree_getter")
load("//bazel/rules/tree_hcp:static_tree_structs.bzl", "static_tree_structs")
load("//bazel/rules/tree_hcp:string_tree_to_static_tree_parser.bzl", "string_tree_to_static_tree_parser")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "unilang_hello_world_gif",
    implementation_deps = [
        "//code/utilities/data_structures/graphics/bitmap/premade:tree_button",
        "//code/utilities/fonts/bdf/complete/unilang:unilang_character_maps",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_drawer",
        "//code/utilities/graphics/cairo/render:cairo_render_settings",
        "//code/utilities/graphics/cairo/render:frame_renderer",
        "//code/utilities/data_structures/graphics/objects/label/style:default_label_styles",
        "//code/utilities/personal/hosting:hosting_repo",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:string_tree_to_buttoned_face_tree",
        "//code/programs/ide/settings:ide_settings_getter",
        "//code/utilities/filesystem/files/temp:temp_dir",
        "//code/utilities/peripheral/keyboard/state:key_codes",
        "//code/utilities/program/wrappers/convert/settings:image_animated_settings",
        "//code/utilities/program/wrappers/convert:convert_image_animator",
        "//code/utilities/program/wrappers/convert:image_transparent",
        "//code/utilities/program/wrappers/gifsicle:image_overlap_layer_remover",
        "//code/programs/ide/settings/data:ide_creation_settings",
        "//code/utilities/colors/converters:rgb_to_zero_one_range",
    ],
    interface_deps = [
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/code:concept_string_tree_getter",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/programs/ide/settings/data:ide_settings",
        "//code/programs/ide/frame:everything_draw_settings",
        "//code/programs/ide/frame:everything_drawer",
        "//code/utilities/filesystem/files/temp:incrementing_tmp_images",
        "//code/utilities/deps/external/tree_hh:lib",
    ],
)
