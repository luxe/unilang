package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "type_relationship")

hcp(
    name = "import_relation_and_label_getter",
    deps = [
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/utilities/linguistics/computer/frontends/parts/header/impl/relationships:type_relationship",
        "//code/utilities/linguistics/computer/frontends/parts/header/impl/relationships/derived_data:related_things_and_their_labels",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "import_relationship_comment_deriver",
    deps = [
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/utilities/linguistics/computer/frontends/parts/header/impl/relationships:import_relation_and_label_getter",
        "//code/utilities/linguistics/computer/frontends/parts/header/settings:import_options",
        "//code/utilities/types/sets:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)
