package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "text_image_maker",
    deps = [
        "//code/utilities/filesystem/files/deleting:lib",
        "//code/utilities/filesystem/files/temp:existing_temp_file",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/wrappers/convert:black_and_white_forcer",
        "//code/utilities/program/wrappers/convert:convert_image_maker",
        "//code/utilities/program/wrappers/convert:draw_text_on_image",
        "//code/utilities/program/wrappers/convert:image_transparent",
        "//code/utilities/program/wrappers/convert:whitespace_image_trimmer",
        "//code/utilities/program/wrappers/convert/settings:draw_text_settings",
        "//code/utilities/program/wrappers/convert/settings:image_settings",
        "//code/utilities/program/wrappers/convert/text_image_maker:text_image_maker_settings",
    ],
)

hcp(
    name = "text_image_maker_settings",
    deps = [
        "//code/utilities/data_structures/dimensions:two_d_dimensions",
        "//code/utilities/data_structures/position",
    ],
)
