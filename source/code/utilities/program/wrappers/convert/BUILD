package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "convert_image_maker",
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/convert/settings:image_settings",
    ],
)


hcp(
    name = "draw_text_on_image",
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/convert/settings:image_settings",
        "//code/utilities/types/strings/transformers/wrap:lib",
    ],
)
