package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_and_hcp_pos(
    name = "buildable_schema_faced_tree",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree:buildable_face_tree",
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
    ],
)