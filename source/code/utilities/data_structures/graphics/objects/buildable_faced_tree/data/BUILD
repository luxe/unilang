package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/hcp:hcp_and_hcp_pos_hdrs_derive.bzl", "hcp_and_hcp_pos_hdrs_derive")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "buildable_face_tree_state",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/select_menu/data:positioned_select_menu",
        "//code/utilities/deps/external/tree_hh:lib",
    ],
)

hcp_and_hcp_pos_hdrs_derive(
    name = "buildable_face_tree",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:buildable_face_tree_state",
    ],
)
