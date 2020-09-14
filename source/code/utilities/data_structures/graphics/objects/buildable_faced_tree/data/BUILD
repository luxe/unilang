package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "buildable_face_tree_state",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/select_menu:positioned_select_menu",
        "@tree",
    ],
)

hcp_and_hcp_pos(
    name = "buildable_face_tree",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:buildable_face_tree_state",
    ],
)
