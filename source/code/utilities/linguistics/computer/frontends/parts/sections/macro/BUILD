package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

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
        "//code/utilities/comments/code/settings:comment_settings",
        "//code/utilities/linguistics/computer/frontends/parts/extern_c/settings/define_check:define_check_end_comment_settings",
        "//code/utilities/linguistics/computer/frontends/parts/extern_c/settings/define_check:define_check_settings",
        "//code/utilities/linguistics/computer/frontends/parts/sections/macro:if_else_style",
        "//code/utilities/linguistics/computer/frontends/parts/sections/macro:macro_redefinition_message_settings",
        "//code/utilities/linguistics/computer/frontends/parts/sections/macro:preprocessor_directives",
        "//code/utilities/linguistics/computer/frontends/parts/sections/macro:redefinition_report_strategy",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
    ],
)
