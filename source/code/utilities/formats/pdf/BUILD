package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "pdf_settings",deps=[
    "//code/utilities/program/wrappers/pandoc/settings:pandoc_pdf_settings",
    "//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_settings",
])

hcp(name = "pdf_creator",deps=[
    "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
    "//code/utilities/formats/pdf:pdf_settings",
    "//code/tools/transcompilers/unilang/main/root_settings:root_settings_getter",
    "//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_str_getter",
    "//code/utilities/types/general:lib",
    "//code/utilities/program/common_actions/exits:lib",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/formats/pdf:latex_template_getter",
    "//code/utilities/formats/pdf:csl_template_getter",
    "//code/tools/transcompilers/unilang/main:program_input",
    "//code/utilities/program/call:lib",
    "//code/utilities/filesystem/files/temp:temp_file",
    "//code/utilities/filesystem/files/temp:existing_temp_file",
    "//code/utilities/program/call/process_spawn:process_spawner",
    "//code/utilities/program/wrappers/pandoc:pandoc_pdf_generator",
    "//code/utilities/program/wrappers/pandoc/settings:pandoc_pdf_settings",
])

hcp(name = "latex_template_getter", deps = [
])

hcp(name = "csl_template_getter", deps = [
])