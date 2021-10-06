package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/hcp:hcp_and_hcp_pos_hdrs_derive.bzl", "hcp_and_hcp_pos_hdrs_derive")

hcp_hdrs_derive(
    name = "fitted_faced_label_graph_creator",
    interface_deps = [
        "//code/utilities/data_structures/graph/conceptually_laid_out_graph",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/premade:faced_label_premades",
        "//code/utilities/data_structures/graphics/objects/fitted_faced_label_graph/data:fitted_faced_label_graph",
    ],
)

hcp_hdrs_derive(
    name = "fitted_faced_label_graph_drawer",
    interface_deps = [
        "//code/utilities/data_structures/graph/conceptually_laid_out_graph",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/arrow:arrow_drawer",
        "//code/utilities/data_structures/graphics/objects/arrow/data:arrow",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_dimension_getter",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_first_name",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/premade:faced_label_premades",
        "//code/utilities/data_structures/graphics/objects/fitted_faced_label_graph/data:fitted_faced_label_graph",
        "//code/utilities/data_structures/graphics/objects/fitted_faced_label_graph/data:positioned_fitted_faced_label_graph",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/types/vectors/operators:lib",
    ],
)
