package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "game_loop",
    deps = [
        "@sfml",
        #"@sfml//:hdrs",
    ],
)

hcp(
    name = "standard_sfml_game_loop",
    deps = [
        "//code/utilities/graphics/sfml:game_loop",
        "//code/utilities/peripheral/display:all_video_modes_printer",
        "@sfml",
    ],
)
