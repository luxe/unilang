package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp_and_hcp_pos(name="face_grid", deps = [
    "//code/utilities/data_structures/graphics/objects/grid/faced:faced_label",
    "//code/utilities/data_structures/line_break:should_line_break",
])

hcp_and_hcp_pos(name="face_tree", deps = [
    "//code/utilities/data_structures/graphics/objects/grid/faced:faced_label",
    "//code/utilities/data_structures/line_break:should_line_break",
    "@tree//:tree"
])

hcp_and_hcp_pos(name="button_face_tree", deps = [
    "//code/utilities/data_structures/graphics/objects/grid/faced:buttoned_faced_label",
    "//code/utilities/data_structures/line_break:should_line_break",
    "@tree//:tree"
])