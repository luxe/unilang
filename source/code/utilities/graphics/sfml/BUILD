package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "game_loop",
    deps = [
        "@sfml",
        #"@sfml//:hdrs",
        #"@system//:SFML_hdrs",
        #"@system//:KHR_hdrs",
        #"@system//:SFML_system",
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
