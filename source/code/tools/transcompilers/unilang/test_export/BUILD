package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "test_comment_getter", deps = [
    "//code/tools/transcompilers/unilang/structure/model:structure",
    "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
    "//code/tools/transcompilers/unilang/options:test_case_attribute_settings",
    "//code/utilities/types/converters:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/strings/transformers/casing:case_modifier",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/types/char:lib",
])

hcp(name = "test_body_getter", deps = [
    "//code/tools/transcompilers/unilang/structure/model/unit_tests:test_case",
    "//code/utilities/types/converters:lib",
])