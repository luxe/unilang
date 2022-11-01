package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "code_to_java_test",
    srcs = ["main.cpp"],
    deps = [
        "//code/programs/transcompilers/code/code_to_java_test/program_options:lib",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/linguistics/computer/frontends/java:java_str_getter",
        "//code/utilities/linguistics/computer/frontends/java:java_test_str_getter",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_default_rule_settings",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_settings",
    ],
)
