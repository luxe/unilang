package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "pandoc_pdf_generator",
    deps = [
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/temp:existing_temp_file",
        "//code/utilities/filesystem/files/temp:temp_file",
        "//code/utilities/formats/pdf:csl_template_getter",
        "//code/utilities/formats/pdf:latex_template_getter",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/program/wrappers/pandoc/settings:pandoc_pdf_settings",
        "//code/utilities/types/general:lib",
    ],
)
