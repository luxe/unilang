package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "noogle_state_getter", deps = [
    "//code/tools/noogle/state:noogle_state",
])

hcp(name = "noogle_state", deps = [
    "//code/tools/noogle/state:noogle_running_stats",
])

hcp(name = "noogle_running_stats", deps = [
    "//code/utilities/data_structures/unique_counter:unique_counter",
    "//code/tools/noogle:queue_state",
])