package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "style_lookup_map",
    deps = [
        "//code/utilities/data_structures/graphics/objects/label/style:label_styles",
    ],
)

hcp(
    name = "style_lookup_map_getter",
    deps = [
        "//code/utilities/code/style_theme:style_lookup_map",
        "//code/utilities/data_structures/graphics/objects/label/style:default_label_styles",
    ],
)
