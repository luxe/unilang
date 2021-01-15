package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "define_guard_settings",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/extern_c/settings/define_check:define_check_end_comment_settings",
        "//code/utilities/linguistics/computer/frontends/parts/extern_c/settings/define_check:define_check_settings",
    ],
)

hcp(
    name = "begin_extern_c_guard_options",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/extern_c/settings/guard_sections:define_guard_settings",
        "//code/utilities/linguistics/computer/frontends/parts/macro:preprocessor_directives",
    ],
)

hcp(
    name = "end_extern_c_guard_options",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/extern_c/settings/guard_sections:define_guard_settings",
        "//code/utilities/linguistics/computer/frontends/parts/macro:preprocessor_directives",
    ],
)
