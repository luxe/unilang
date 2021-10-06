package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/hcp:hcp_and_hcp_pos_hdrs_derive.bzl", "hcp_and_hcp_pos_hdrs_derive")

hcp_hdrs_derive(
    name = "label_face",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
    ],
)

hcp_and_hcp_pos_hdrs_derive(
    name = "faced_label",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label_state",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_state",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label_style",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:label_face",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_style",
    interface_deps = [
    ],
)
