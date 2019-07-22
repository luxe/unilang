package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "pdf_settings",deps=[
])

hcp(name = "pdf_creator",deps=[
    "//code/transcompilers/unilang/structure/model:inlined_structures",
    "//code/utilities/pdf:pdf_settings",
    "//code/transcompilers/unilang/main/root_settings:root_settings_getter",
    "//code/transcompilers/unilang/compiler-frontends/markdown:markdown_str_getter",
    "//code/utilities/types/general:lib",
    "//code/utilities/exits:lib",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/pdf:latex_template_getter",
    "//code/transcompilers/unilang/main:program_input",
    "//code/utilities/shell:lib",
    "//code/utilities/filesystem/files:temp_file",
    "//code/utilities/shell/process_spawn:process_spawner",
])

hcp(name = "latex_template_getter", deps = [
])