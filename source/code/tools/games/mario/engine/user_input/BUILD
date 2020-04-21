package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")

hcp(name = "user_action", deps = [
])

hcp(name = "user_action_getter", deps = [
    "//code/utilities/x11/events:global_event_listener",
    "//code/tools/games/mario/engine/user_input:user_action",
    "//code/utilities/x11/data:main_x11_state",
    "//code/utilities/types/booleans:lib",
])