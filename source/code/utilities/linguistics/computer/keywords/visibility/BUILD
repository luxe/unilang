package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "visibility_strs",
    deps = [
    ],
)

hcp(
    name = "language_visibility_getter",
    deps = [
        "//code/utilities/code/query:data_member_visibility",
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/keywords/visibility:visibility_strs",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)

hcp(
    name = "visibility_keyword_getter",
    deps = [
        "//code/utilities/code/query:data_member_visibility",
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/keywords/visibility:language_visibility_getter",
        "//code/utilities/linguistics/computer/keywords/visibility:visibility_strs",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)
