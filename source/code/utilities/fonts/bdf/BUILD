package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/unilang:generate_unilang_token_files.bzl", "generate_unilang_token_files")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "character_segment_map",
    deps = ["//code/utilities/fonts/bdf/settings:character_segment"]
)

hcp(
    name = "character_segment_map_creator",
    deps = [
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/fonts/bdf:character_segment_map",
    ]
)