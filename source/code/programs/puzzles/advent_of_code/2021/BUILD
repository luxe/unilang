package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["//code/programs/puzzles/advent_of_code/2021:task_executer"],
)

hcp_hdrs_derive(
    name = "task_executer",
    interface_deps = [
        "//code/programs/puzzles/advent_of_code:advent_of_code_input_getter",
        "//code/programs/puzzles/advent_of_code/2021:day_1",
    ],
)

hcp_hdrs_derive(
    name = "day_1",
    interface_deps = [
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)
