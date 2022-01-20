package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/transcompilers/old_unilang/language-and-theme-creator/sublime:unilang_file_creator",
        "//code/utilities/fonts/bdf/complete:font_creator",
        "//code/utilities/fonts/bdf/complete/unilang:unilang_font_creation_settings",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

cc_binary(
    name = "language-and-theme-creator",
    srcs = ["main.cpp"],
    deps = [":task_executer"],
)
