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
        "//code/tools/puzzles/advent_of_code/2020:day_2",
        "//code/tools/puzzles/advent_of_code/2020:day_3",
    ],
)

hcp(
    name = "day_1",
    deps = [
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "day_2",
    deps = [
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/observers/counters:lib",
    ],
)

hcp(
    name = "day_3",
    deps = [
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/observers/counters:lib",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/string_grid:string_grid_builder",
    ],
)
