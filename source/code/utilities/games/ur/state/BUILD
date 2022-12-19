package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "ur_game_state",
    interface_deps = [
        "//code/utilities/games/ur/state:ur_player_state",
        "//code/utilities/deps/stl/unordered_set:lib",
    ],
)

hcp_hdrs_derive(
    name = "ur_player",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "ur_player_state",
    interface_deps = [
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
