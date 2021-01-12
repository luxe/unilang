package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")


hcp(
    name = "java_str_getter",
    deps = [
        "//code/utilities/contributor:contributor",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_settings",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/time/date:lib",
        "//code/utilities/types/strings/observers/converting:lib",
    ],
)