package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "include_guard_wrap_printer",
    deps = [
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/meta:meta_section",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
    ],
)

hcp(
    name = "code_wrap_printer",
    deps = [
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/meta:meta_section",
        "//code/utilities/streams/filestreams:lib",
    ],
)

hcp(
    name = "boilerplate_printer",
    deps = [
        "//code/tools/transcompilers/old_unilang/boilerplate_printer:code_wrap_printer",
        "//code/tools/transcompilers/old_unilang/boilerplate_printer:include_guard_wrap_printer",
        "//code/utilities/linguistics/computer/frontends/parts/extern_c:extern_wrap_printer",
        "//code/tools/transcompilers/old_unilang/boilerplate_printer/header:header_printer",
        "//code/tools/transcompilers/old_unilang/boilerplate_printer/meta_block:meta_block_printer",
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/tools/transcompilers/old_unilang/structure/print/export_file_settings",
        "//code/utilities/linguistics/computer:source_language",
    ],
)
