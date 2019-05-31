package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")


cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"]
)

hcp(name="hsv_to_rgb_converter",deps = [
    "//code/utilities/data_structures/color:hsv_color",
    "//code/utilities/data_structures/color:rgb_color",
])