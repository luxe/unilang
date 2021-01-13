package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "markdown_exporter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/markdown/settings:markdown_settings",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/linguistics/computer/frontends/markdown:markdown_str_getter",
    ],
)

hcp(
    name = "markdown_str_getter",
    deps = [
        "//code/utilities/comments/doxygen/maker:grammar_adjuster",
        "//code/utilities/linguistics/computer/frontends/markdown/settings:markdown_settings",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/frontends/markdown:markdown_header_getter",
        "//code/utilities/linguistics/computer/frontends/markdown:markdown_image_getter",
        "//code/utilities/linguistics/computer/frontends/markdown:markdown_sentence_extra_getter",
        "//code/utilities/linguistics/computer/frontends/markdown:markdown_title_getter",
        "//code/utilities/program/call:lib",
        "//code/utilities/time/date:lib",
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
    name = "markdown_settings_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/markdown/settings:markdown_settings",
    ],
)

hcp(
    name = "markdown_header_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/markdown/settings:markdown_settings",
        "//code/utilities/code:concept_static_tree_structs",
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
        "//code/utilities/linguistics/computer/frontends/markdown/settings:markdown_settings",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/linguistics/computer/frontends/markdown/images:classic_markdown_image",
        "//code/utilities/linguistics/computer/frontends/markdown/images:html_markdown_image",
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
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/frontends/markdown:markdown_header_getter",
        "//code/utilities/linguistics/computer/frontends/markdown:markdown_sentence_extra_getter",
        "//code/utilities/program/call:lib",
        "//code/utilities/time/date:lib",
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
    name = "markdown_sentence_extra_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/markdown/settings:markdown_settings",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/linguistics/computer/frontends/markdown:markdown_code_getter",
        "//code/utilities/linguistics/computer/frontends/markdown:markdown_image_getter",
        "//code/utilities/linguistics/computer/frontends/markdown:markdown_table_getter",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "markdown_table_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/markdown/settings:markdown_settings",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "markdown_code_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/markdown/settings:markdown_settings",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)
