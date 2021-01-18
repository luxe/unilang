package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "load_getter",
    deps = [
        "//code/tools/transcompilers/old_unilang/compiler-frontends/bazel/bazel_printer:path_to_bazel_path",
        "//code/tools/transcompilers/old_unilang/options/bazel:bazel_build_object",
        "//code/tools/transcompilers/old_unilang/options/bazel:bazel_load_db_settings",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/sets:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "path_to_bazel_path",
    deps = [
        "//code/utilities/types/char:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/creators:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/other:lib",
    ],
)

hcp(
    name = "top_comment_getter",
    deps = [
        "//code/tools/transcompilers/old_unilang/options/bazel:build_rule_settings",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_copyright_getter",
        "//code/utilities/types/strings/creators:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "build_info_extractor",
    deps = [
        "//code/tools/transcompilers/old_unilang/dependency_graph_creator:code_graph",
        "//code/tools/transcompilers/old_unilang/options/bazel:build_rule_settings",
        "//code/tools/transcompilers/old_unilang/options/bazel:language_to_build_object",
        "//code/tools/transcompilers/old_unilang/user-frontend/artifact_actions:artifact_guesser",
    ],
)

hcp(
    name = "target_name_deriver",
    deps = [
        "//code/tools/transcompilers/old_unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "deps_printer",
    deps = [
        "//code/tools/transcompilers/old_unilang/compiler-frontends/bazel/bazel_printer:path_to_bazel_path",
        "//code/tools/transcompilers/old_unilang/options/bazel:build_rule_settings",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "package_getter",
    deps = [
        "//code/tools/transcompilers/old_unilang/options/bazel:build_rule_settings",
    ],
)
