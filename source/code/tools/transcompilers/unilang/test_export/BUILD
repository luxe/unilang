package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "test_comment_getter",
    deps = [
        "//code/tools/transcompilers/unilang/options:test_case_attribute_settings",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
    ],
)

hcp(
    name = "test_body_getter",
    deps = [
        "//code/tools/transcompilers/unilang/structure/model/unit_tests:test_case",
        "//code/utilities/types/converters:lib",
    ],
)
