package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")


hcp(
    name = "boilerplate_printer",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/tools/transcompilers/old_unilang/structure/print/export_file_settings:export_file_settings",
        "//code/utilities/types/vectors/observers:lib",
    ],
)
