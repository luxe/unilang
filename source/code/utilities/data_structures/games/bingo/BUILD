package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "bingo_board",
    interface_deps = [
        "//code/utilities/data_structures/marked_number:marked_number",
    ],
)

hcp_hdrs_derive(
    name = "bingo_boards",
    interface_deps = [
        "//code/utilities/data_structures/games/bingo:bingo_board",
    ],
)

hcp_hdrs_derive(
    name = "bingo_boards_getter",
    interface_deps = [
        "//code/utilities/data_structures/games/bingo:bingo_boards",
    ],
)

hcp_hdrs_derive(
    name = "bingo_simulator",
    interface_deps = [
        "//code/utilities/data_structures/games/bingo:bingo_boards",
    ],
)