package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "special_filetype_suffix_settings")

hcp(
    name = "filetype_suffix_settings",
    deps = ["special_filetype_suffix_settings"],
)

hcp(
    name = "codetype_suffix_settings",
    deps = ["filetype_suffix_settings"],
)

hcp(
    name = "general_filesystem_naming",
    deps = [
        "codetype_suffix_settings",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
    ],
)

enum_cpp(
    name = "object_code_partition_method",
    values = [
        "one",
        "two",
        "three",
    ],
)

enum_cpp(
    name = "global_code_partition_method",
    values = [
        "one",
        "two",
        "three",
    ],
)

hcp(
    name = "filesystem_partioning",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/filesystem:global_code_partition_method",
        "//code/utilities/linguistics/computer/frontends/parts/filesystem:object_code_partition_method",
    ],
)

hcp(
    name = "filesystem_settings",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/filesystem:filesystem_partioning",
        "//code/utilities/linguistics/computer/frontends/parts/filesystem:general_filesystem_naming",
    ],
)
