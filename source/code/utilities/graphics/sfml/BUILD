package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "game_loop",
    deps = [
        "//code/utilities/deps/external/sfml:lib",
        "//code/utilities/deps/external/kairos:lib",
    ],
)

hcp(
    name = "standard_sfml_game_loop",
    deps = [
        "//code/utilities/graphics/sfml:game_loop",
        "//code/utilities/peripheral/display:all_video_modes_printer",
        "//code/utilities/deps/external/sfml:lib",
    ],
)
