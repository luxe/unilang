package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

#player boards are 9x9

hcp(name = "piece")

hcp(
    name = "piece_getter",
    deps = [
        "//code/utilities/games/patchwork/data:piece",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(name = "board")

hcp(
    name = "board_getter",
    deps = [
        "//code/utilities/games/patchwork/data:board",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)
