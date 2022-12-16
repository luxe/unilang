package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

hcp_hdrs_derive(
    name = "moving_text",
    interface_deps = [
        "//code/utilities/deps/external/sfml:lib",
    ],
)

hcp_hdrs_derive(
    name = "named_rectangle",
    interface_deps = [
        "//code/utilities/deps/external/sfml:lib",
    ],
)

hcp_hdrs_derive(
    name = "named_rectangles",
    interface_deps = [
        "//code/utilities/graphics/sfml/data:named_rectangle",
        "//code/utilities/deps/external/sfml:lib",
    ],
)
