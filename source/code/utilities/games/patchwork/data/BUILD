package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

#player boards are 9x9

hcp_hdrs_derive(name = "piece")

hcp_hdrs_derive(
    name = "piece_getter",
    interface_deps = [
        "//code/utilities/games/patchwork/data:piece",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp_hdrs_derive(name = "board")

hcp_hdrs_derive(
    name = "board_getter",
    interface_deps = [
        "//code/utilities/games/patchwork/data:board",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)
