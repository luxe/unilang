package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "extern_c_guard_options",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/extern_c/settings/guard_sections:begin_extern_c_guard_options",
        "//code/utilities/linguistics/computer/frontends/parts/extern_c/settings/guard_sections:end_extern_c_guard_options",
    ],
)
