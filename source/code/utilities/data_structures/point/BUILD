package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "point")

hcp(name = "point_mover", deps = [
    "//code/utilities/data_structures:compass_direction",
    "//code/utilities/data_structures:compass_direction_diagnonal",
    "//code/utilities/data_structures/point:point",
])