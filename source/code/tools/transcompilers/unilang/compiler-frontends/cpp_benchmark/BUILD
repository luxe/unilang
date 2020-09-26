package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "cpp_benchmark_exporter",
    deps = [
        "//code/tools/transcompilers/unilang/boilerplate_printer",
        "//code/tools/transcompilers/unilang/compiler-frontends/cpp_benchmark:benchmark_coverage_summary_getter",
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/options/language-specific/cpp:cpp_benchmark_export_settings",
        "//code/tools/transcompilers/unilang/structure/adjust:structure_adjuster",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/tools/transcompilers/unilang/structure/print:file_printer",
        "//code/tools/transcompilers/unilang/structure/print:namespace_printer",
        "//code/tools/transcompilers/unilang/structure/print:shared_printer",
        "//code/tools/transcompilers/unilang/structure/print/export_file_settings",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
    ],
)

hcp(
    name = "cpp_benchmark_options_getter",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/cpp:cpp_benchmark_export_settings",
        "//code/tools/transcompilers/unilang/options/sections/meta/organizations:organization",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/tools/transcompilers/unilang/structure/print/filename:file_name_getter",
        "//code/utilities/personal/life:company_getter",
        "//code/utilities/program/common_actions/exits:lib",
    ],
)

hcp(
    name = "benchmark_coverage_summary_getter",
    deps = [
        "//code/tools/transcompilers/unilang/design/normal:method_sorter",
        "//code/tools/transcompilers/unilang/design/normal/data:subgroup_methods",
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/options/language-specific/cpp:cpp_benchmark_export_settings",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/inflection:inflection_converter",
        "//code/utilities/types/strings/transformers/inflection/getters:inflection_settings_getter",
        "//code/utilities/types/strings/transformers/inflection/settings:inflection_settings",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)
