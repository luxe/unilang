package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp_hdrs_derive(
    name = "puyo",
    data = ["@PuyoPuyoAssets//:all"],
    deps = [],
)

hcp_hdrs_derive(
    name = "english_sounds",
    data = ["@english_sounds//:all"],
    deps = [],
)

hcp_hdrs_derive(
    name = "playing_card_assets",
    data = ["@playing_card_assets//:all"],
    implementation_deps = [
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
    interface_deps = [
        "//code/utilities/data_structures:playing_card",
    ],
)

hcp_hdrs_derive(
    name = "chrome_drivers",
    data = ["@chrome_drivers//:all"],
    deps = [],
)

hcp_hdrs_derive(
    name = "dogecoin_tools",
    interface_deps = [
        "//code/utilities/deps/external/dogecoin_tools:lib"
    ],
)
