package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name="textured_sprite",deps = [
    "@sfml//:sfml"
])

hcp(name="textured_sprite_loader",deps = [
    "//code/utilities/graphics/sfml/sprite:textured_sprite",
])