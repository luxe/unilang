package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "extern_wrap_printer",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/extern_c:macro_define_check_getter",
        "//code/utilities/linguistics/computer/frontends/parts/extern_c:macro_endif_getter",
        "//code/utilities/linguistics/computer/frontends/parts/extern_c/settings:extern_c_guard_options",
        "//code/utilities/streams/filestreams:lib",
    ],
)

hcp(
    name = "macro_define_check_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/extern_c/settings/define_check:define_check_settings",
        "//code/utilities/types/strings/creators:lib",
    ],
)

hcp(
    name = "macro_endif_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/extern_c/settings/define_check:define_check_end_comment_settings",
        "//code/utilities/linguistics/computer/frontends/parts/sections/macro:preprocessor_directives",
    ],
)
