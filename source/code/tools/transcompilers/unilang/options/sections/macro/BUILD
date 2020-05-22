package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "if_else_style")

cpp_object(name = "redefinition_report_strategy")

hcp(name = "preprocessor_directives")

hcp(
    name = "macro_redefinition_message_settings",
    deps = ["redefinition_report_strategy"],
)

hcp(
    name = "macro_options",
    deps = [
        "//code/tools/transcompilers/unilang/options/comment:comment_settings",
        "//code/tools/transcompilers/unilang/options/sections/extern_c/define_check:define_check_end_comment_settings",
        "//code/tools/transcompilers/unilang/options/sections/extern_c/define_check:define_check_settings",
        "//code/tools/transcompilers/unilang/options/sections/macro:if_else_style",
        "//code/tools/transcompilers/unilang/options/sections/macro:macro_redefinition_message_settings",
        "//code/tools/transcompilers/unilang/options/sections/macro:preprocessor_directives",
        "//code/tools/transcompilers/unilang/options/sections/macro:redefinition_report_strategy",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
    ],
)
