package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "java_str_getter",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/frontends/java/parts:boilerplate_getter",
        "//code/utilities/linguistics/computer/frontends/java/parts:class_getter",
        "//code/utilities/linguistics/computer/frontends/java/parts:imports_getter",
        "//code/utilities/linguistics/computer/frontends/java/parts:package_name_getter",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_settings",
        "//code/utilities/program/call:lib",
        "//code/utilities/time/date:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)
