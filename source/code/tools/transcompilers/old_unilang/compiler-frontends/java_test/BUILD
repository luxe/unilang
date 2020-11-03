package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "java_test_exporter",
    deps = [
        "//code/tools/transcompilers/old_unilang/compiler-frontends/java_test:java_test_str_getter",
        "//code/tools/transcompilers/old_unilang/doxygen_block_printer:grammar_adjuster",
        "//code/tools/transcompilers/old_unilang/options/language-specific/java:java_test_settings",
        "//code/tools/transcompilers/old_unilang/options/manipulation:case_adjustment_settings",
        "//code/tools/transcompilers/old_unilang/structure/adjust:casing_adjuster",
        "//code/tools/transcompilers/old_unilang/structure/adjust:structure_adjuster",
        "//code/tools/transcompilers/old_unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/tools/transcompilers/old_unilang/structure/print:struct_derivers",
        "//code/tools/transcompilers/old_unilang/structure/print/filename:file_name_getter",
        "//code/tools/transcompilers/old_unilang/structure/query:mock_test_checker",
        "//code/tools/transcompilers/old_unilang/structure/query:redis_test_checker",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "java_test_str_getter",
    deps = [
        "//code/tools/transcompilers/old_unilang/boilerplate_printer",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/java/parts:import_getter",
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/options/language-specific/java:java_test_settings",
        "//code/tools/transcompilers/old_unilang/structure/adjust:structure_adjuster",
        "//code/tools/transcompilers/old_unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/tools/transcompilers/old_unilang/structure/print:doxygen_block_printer",
        "//code/tools/transcompilers/old_unilang/structure/print:shared_printer",
        "//code/tools/transcompilers/old_unilang/structure/print/filename:file_name_getter",
        "//code/tools/transcompilers/old_unilang/test_export:test_body_getter",
        "//code/tools/transcompilers/old_unilang/test_export:test_comment_getter",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "java_test_settings_getter",
    deps = [
        "//code/tools/transcompilers/old_unilang/options/language-specific/java:java_test_settings",
        "//code/tools/transcompilers/old_unilang/options/sections/meta/organizations:organization",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/utilities/personal/life:company_getter",
        "//code/utilities/program/common_actions/exits:lib",
    ],
)
