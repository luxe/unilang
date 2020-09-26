package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "ur_game_state",
    deps = [
        "//code/utilities/games/ur/state:ur_player_state",
    ],
)

hcp(
    name = "ur_player",
    deps = [
    ],
)

hcp(
    name = "ur_player_state",
    deps = [
        "//code/utilities/games/ur/state:player_phase",
        "//code/utilities/games/ur/state:ur_player",
    ],
)

enum_cpp(
    name = "player_phase",
    values = [
        "roll",
        "choose",
        "move",
        "wait",
    ],
)
