package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp(name="label_face", deps = [
    "//code/utilities/data_structures/graphics/objects/label:label_settings",
])


hcp_and_hcp_pos(name="faced_label", deps = [
    "//code/utilities/data_structures/graphics/objects/grid/faced:label_face",
])

hcp_and_hcp_pos(name="buttoned_faced_label", deps = [
    "//code/utilities/data_structures/graphics/objects/grid/faced:faced_label",
    "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:multi_color_bitmap_button",
])

hcp(name="faced_label_converter", deps = [
    "//code/utilities/data_structures/graphics/objects/grid/faced:faced_label",
    "//code/utilities/data_structures/graphics/objects/grid/faced:positioned_faced_label",
])
