package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "begin_include_guard_options",
)

hcp(
    name = "end_include_guard_options",
    deps = [
        "//code/utilities/comments/language:comment_style",
    ],
)

hcp(
    name = "include_guard_options",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/include_guard:begin_include_guard_options",
        "//code/utilities/linguistics/computer/frontends/parts/include_guard:end_include_guard_options",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
    ],
)
