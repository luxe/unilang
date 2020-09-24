package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "converters",
    deps = [
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "@sfml",
    ],
)

hcp(
    name = "hsv_to_rgb_converter",
    deps = [
        "//code/utilities/data_structures/color:hsv_color",
        "//code/utilities/data_structures/color:rgb_color",
    ],
)
