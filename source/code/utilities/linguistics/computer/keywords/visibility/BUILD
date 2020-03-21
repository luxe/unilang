package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "visibility_strs", deps = [
])

hcp(name = "language_visibility_getter", deps = [
    "//code/utilities/linguistics/computer:source_language",
    "//code/tools/transcompilers/unilang/structure/model/sections:structure_enums",
    "//code/utilities/types/map:lib",
    "//code/utilities/types/strings/transformers/casing:lib",
    "//code/utilities/linguistics/computer/keywords/visibility:visibility_strs",
])

hcp(name = "visibility_keyword_getter", deps = [
    "//code/utilities/linguistics/computer:source_language",
    "//code/tools/transcompilers/unilang/structure/model/sections:structure_enums",
    "//code/utilities/types/map:lib",
    "//code/utilities/types/strings/transformers/casing:lib",
    "//code/utilities/linguistics/computer/keywords/visibility:visibility_strs",
    "//code/utilities/linguistics/computer/keywords/visibility:language_visibility_getter",
])