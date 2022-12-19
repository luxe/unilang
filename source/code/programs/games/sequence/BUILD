package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp_hdrs_derive(
    name = "task_executer",
    interface_deps = [
        "//code/programs/games/sequence:frontend_drawer",
        "//code/programs/games/sequence/data:game_state",
        "//code/utilities/assets:playing_card_assets",
        "//code/utilities/data_structures:playing_card",
        "//code/utilities/deps/external/crow:lib",
        "//code/utilities/formats/html:basic_html_template_getter",
        "//code/utilities/games/sequence:board_getter",
        "//code/utilities/games/sequence:deck_getter",
        "//code/utilities/image:data_uri_getter",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp_hdrs_derive(
    name = "frontend_drawer",
    interface_deps = [
        "//code/programs/games/sequence/data:game_state",
        "//code/utilities/assets:playing_card_assets",
        "//code/utilities/data_structures:playing_card",
        "//code/utilities/deps/external/crow:lib",
        "//code/utilities/formats/html:basic_html_template_getter",
        "//code/utilities/image:data_uri_getter",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

cpp_main(
    name = "sequence",
    deps = [
        "//code/programs/games/sequence:task_executer",
        "//code/utilities/deps/external/crow:lib",
        "//code/utilities/program/call:lib",
    ],
)
