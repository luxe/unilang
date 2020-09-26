package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "type_relationship")

hcp(
    name = "import_relation_and_label_getter",
    deps = [
        "//code/tools/transcompilers/unilang/boilerplate_printer/header/relationships:type_relationship",
        "//code/tools/transcompilers/unilang/boilerplate_printer/header/relationships/derived_data:related_things_and_their_labels",
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "import_relationship_comment_deriver",
    deps = [
        "//code/tools/transcompilers/unilang/boilerplate_printer/header/relationships:import_relation_and_label_getter",
        "//code/tools/transcompilers/unilang/options/sections/import:import_options",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/utilities/types/sets:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)
