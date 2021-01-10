package(default_visibility = ["//visibility:public"])
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

cpp_object(name = "stb_image",
    deps = [
    "@stb"
    ],
)

hcp(
    name = "stb_image_setter",
    deps = [
        "//code/utilities/data_structures/graphics/image:positioned_image_data",
        "//code/utilities/image:stb_image",
    ],
)