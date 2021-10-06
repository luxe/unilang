package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

hcp(
    name = "moving_text",
    deps = [
        "@sfml",
    ],
)

hcp(
    name = "named_rectangle",
    deps = [
        "@sfml",
    ],
)

hcp(
    name = "named_rectangles",
    deps = [
        "//code/utilities/graphics/sfml/data:named_rectangle",
        "@sfml",
    ],
)
