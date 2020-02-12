package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "type_relationship")

hcp(name = "import_relation_and_label_getter", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/boilerplate_printer/header/relationships:type_relationship",
"//code/tools/transcompilers/unilang/boilerplate_printer/header/relationships/derived_data:related_things_and_their_labels",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/program/common_actions/exits:lib",
])

hcp(name = "import_relationship_comment_deriver", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/sections/import:import_options",
"//code/tools/transcompilers/unilang/boilerplate_printer/header/relationships:import_relation_and_label_getter",
"//code/utilities/types/sets:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/types/vectors/converters:lib",
])