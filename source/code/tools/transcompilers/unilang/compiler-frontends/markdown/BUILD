package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "markdown_exporter",
    deps = [
        "//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_str_getter",
        "//code/tools/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
        "//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_settings",
        "//code/tools/transcompilers/unilang/options/manipulation:case_adjustment_settings",
        "//code/tools/transcompilers/unilang/structure/adjust:casing_adjuster",
        "//code/tools/transcompilers/unilang/structure/adjust:structure_adjuster",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/tools/transcompilers/unilang/structure/print:struct_derivers",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "markdown_str_getter",
    deps = [
        "//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_header_getter",
        "//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_image_getter",
        "//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_sentence_extra_getter",
        "//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_title_getter",
        "//code/tools/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
        "//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_settings",
        "//code/tools/transcompilers/unilang/options/manipulation:case_adjustment_settings",
        "//code/tools/transcompilers/unilang/structure/adjust:casing_adjuster",
        "//code/tools/transcompilers/unilang/structure/adjust:structure_adjuster",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/tools/transcompilers/unilang/structure/print:struct_derivers",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/time/date:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "markdown_settings_getter",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_settings",
    ],
)

hcp(
    name = "markdown_header_getter",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_settings",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/utilities/contributor",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "markdown_image_getter",
    deps = [
        "//code/tools/transcompilers/unilang/compiler-frontends/markdown/images:classic_markdown_image",
        "//code/tools/transcompilers/unilang/compiler-frontends/markdown/images:html_markdown_image",
        "//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_settings",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/utilities/contributor",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "markdown_title_getter",
    deps = [
        "//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_header_getter",
        "//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_sentence_extra_getter",
        "//code/tools/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
        "//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_settings",
        "//code/tools/transcompilers/unilang/options/manipulation:case_adjustment_settings",
        "//code/tools/transcompilers/unilang/structure/adjust:casing_adjuster",
        "//code/tools/transcompilers/unilang/structure/adjust:structure_adjuster",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/tools/transcompilers/unilang/structure/print:struct_derivers",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/time/date:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "markdown_sentence_extra_getter",
    deps = [
        "//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_code_getter",
        "//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_image_getter",
        "//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_table_getter",
        "//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_settings",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/utilities/contributor",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "markdown_table_getter",
    deps = [
        "//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_image_getter",
        "//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_settings",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/utilities/contributor",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "markdown_code_getter",
    deps = [
        "//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_image_getter",
        "//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_settings",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/utilities/contributor",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)
