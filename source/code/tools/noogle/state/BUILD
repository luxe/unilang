package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "noogle_state_getter",
    deps = [
        "//code/tools/noogle:meta_settings",
        "//code/tools/noogle/settings:default_settings_getter",
        "//code/tools/noogle/state:noogle_state",
        "//code/utilities/program/inputs/config:config_monitor",
    ],
)

hcp(
    name = "noogle_state",
    deps = [
        "//code/tools/noogle/settings:noogle_settings",
        "//code/tools/noogle/state:message_queues",
        "//code/tools/noogle/state:noogle_running_stats",
        "//code/utilities/program/inputs/config:config_monitor_settings",
    ],
)

hcp(
    name = "noogle_running_stats",
    deps = [
        "//code/tools/noogle:queue_state",
        "//code/tools/noogle/state:display_style",
        "//code/utilities/data_structures/counters/unique_counter",
    ],
)

hcp(
    name = "message_queues",
    deps = [
        "//code/tools/noogle:noogle_result",
        "//code/utilities/data_structures/queue:finishable_safe_queue",
    ],
)

enum_cpp(
    name = "display_style",
    values = [
        "all",
        "date",
        "no_date",
    ],
)
