package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "load_getter", deps = [
"//code/transcompilers/unilang/options/bazel:bazel_build_object",
"//code/transcompilers/unilang/options/bazel:bazel_load_db_settings",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/char:lib",
"//code/utilities/types/sets:lib",
"//code/transcompilers/unilang/bazel_printer:path_to_bazel_path",
])

hcp(name = "path_to_bazel_path", deps = [
    "//code/utilities/types/general:lib",
    "//code/utilities/types/strings/transformers/other:lib",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/types/char:lib",
    "//code/utilities/types/strings/creators:lib",
])

hcp(name = "top_comment_getter", deps = [
"//code/transcompilers/unilang/options/bazel:build_rule_settings",
"//code/transcompilers/unilang/boilerplate_printer/meta_block/sections:meta_copyright_getter",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/strings/creators:lib",
])

hcp(name = "build_info_extractor",deps = [
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/options/bazel:language_to_build_object",
"//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_guesser",
"//code/transcompilers/unilang/options/bazel:build_rule_settings",
])

hcp(name = "target_name_deriver",deps = [
"//code/transcompilers/unilang/structure/model:inlined_structures",
"//code/transcompilers/unilang/structure/model:structure",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/char:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
])

hcp(name = "deps_printer", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/bazel:build_rule_settings",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/char:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/bazel_printer:path_to_bazel_path",
])

hcp(name = "package_getter", deps = [
"//code/transcompilers/unilang/options/bazel:build_rule_settings",
])