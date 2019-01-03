package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "special_filetype_suffix_settings")
hcp(name = "filetype_suffix_settings", deps = ["special_filetype_suffix_settings"])
hcp(name = "codetype_suffix_settings", deps = ["filetype_suffix_settings"])

hcp(name = "general_filesystem_naming",
deps = ["codetype_suffix_settings",
"//code/utilities/types/strings/transformers/casing:case_format_style"
])