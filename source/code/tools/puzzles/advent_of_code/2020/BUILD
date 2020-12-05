package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["//code/tools/puzzles/advent_of_code/2020:task_executer"],
)

hcp(
    name = "task_executer",
    deps = [
        "//code/tools/puzzles/advent_of_code:advent_of_code_input_getter",
        "//code/tools/puzzles/advent_of_code/2020:day_1",
    ],
)

hcp(
    name = "day_1",
    deps = [
    ],
)