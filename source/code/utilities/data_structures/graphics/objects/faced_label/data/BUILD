package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp(
    name = "label_face",
    deps = [
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
    ],
)

hcp_and_hcp_pos(
    name = "faced_label",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label_state",
    ],
)

hcp(
    name = "faced_label_state",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label_style",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:label_face",
    ],
)

hcp(
    name = "faced_label_style",
    deps = [
    ],
)
