package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "sprite", deps = [
])

hcp(name = "sprite_loader", deps = [
    "//code/utilities/x11/sprite:sprite",
    "//code/utilities/x11/data:main_x11_state",
])