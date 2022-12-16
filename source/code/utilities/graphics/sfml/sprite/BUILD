package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "textured_sprite",
    interface_deps = [
        "//code/utilities/deps/external/sfml:lib",
    ],
)

hcp_hdrs_derive(
    name = "textured_sprite_loader",
    interface_deps = [
        "//code/utilities/graphics/sfml/sprite:textured_sprite",
    ],
)
