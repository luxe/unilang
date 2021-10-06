package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "reassignment_strs",
    deps = [
    ],
)

hcp(
    name = "language_reassignment_getter",
    deps = [
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/keywords/reassignment:reassignment_strs",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)

hcp(
    name = "reassignment_keyword_getter",
    deps = [
        "//code/utilities/code:reassignability",
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/keywords/reassignment:language_reassignment_getter",
        "//code/utilities/linguistics/computer/keywords/reassignment:reassignment_strs",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)
