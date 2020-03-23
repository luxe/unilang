package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "java_test_exporter", deps = [
    "//code/tools/transcompilers/unilang/structure/model:structure",
    "//code/tools/transcompilers/unilang/contributor:contributor",
    "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
    "//code/tools/transcompilers/unilang/options/language-specific/java:java_test_settings",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/types/converters:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/tools/transcompilers/unilang/structure/print:struct_derivers",
    "//code/utilities/types/strings/transformers/casing:case_modifier",
    "//code/utilities/program/call:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/tools/transcompilers/unilang/options/manipulation:case_adjustment_settings",
    "//code/tools/transcompilers/unilang/structure/adjust:casing_adjuster",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/types/vectors/converters:lib",
    "//code/tools/transcompilers/unilang/structure/adjust:structure_adjuster",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/types/char:lib",
    "//code/tools/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
    "//code/tools/transcompilers/unilang/compiler-frontends/java_test:java_test_str_getter",
    "//code/tools/transcompilers/unilang/structure/print/filename:file_name_getter",
])

hcp(name = "java_test_str_getter", deps = [
    "//code/tools/transcompilers/unilang/structure/model:structure",
    "//code/tools/transcompilers/unilang/contributor:contributor",
    "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
    "//code/tools/transcompilers/unilang/options/language-specific/java:java_test_settings",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/types/converters:lib",
    "//code/utilities/types/strings/transformers/casing:case_modifier",
    "//code/utilities/program/call:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/types/vectors/converters:lib",
    "//code/tools/transcompilers/unilang/structure/adjust:structure_adjuster",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/types/strings/observers/converting:lib",
    "//code/tools/transcompilers/unilang/boilerplate_printer:boilerplate_printer",
    "//code/tools/transcompilers/unilang/structure/print/filename:file_name_getter",
    "//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
])

hcp(name = "java_test_settings_getter", deps = [
    "//code/tools/transcompilers/unilang/options/language-specific/java:java_test_settings",
    "//code/tools/transcompilers/unilang/options/sections/meta/organizations:organization",
    "//code/tools/transcompilers/unilang/structure/model:structure",
    "//code/utilities/program/common_actions/exits:lib",
    "//code/utilities/personal/life:company_getter",
])