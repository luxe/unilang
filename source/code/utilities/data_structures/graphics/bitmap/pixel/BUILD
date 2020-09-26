package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "pixel_settings",
    deps = [
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/position",
    ],
)

hcp(
    name = "pixel_slider",
    deps = [
        "//code/utilities/time/cycle_clock",
    ],
)
