package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "textured_sprite",
    deps = [
        "@sfml",
    ],
)

hcp(
    name = "textured_sprite_loader",
    deps = [
        "//code/utilities/graphics/sfml/sprite:textured_sprite",
    ],
)
