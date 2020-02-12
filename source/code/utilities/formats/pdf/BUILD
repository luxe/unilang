package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "pdf_settings",deps=[
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
    "//code/tools/transcompilers/unilang/main:program_input",
    "//code/utilities/shell:lib",
    "//code/utilities/filesystem/files/temp:temp_file",
    "//code/utilities/filesystem/files/temp:existing_temp_file",
    "//code/utilities/shell/process_spawn:process_spawner",
])

hcp(name = "latex_template_getter", deps = [
])