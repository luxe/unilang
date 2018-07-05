package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "load_getter", deps = [
"//code/transcompilers/unilang/options/bazel:bazel_build_object",
"//code/transcompilers/unilang/options/bazel:bazel_load_db_settings",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/char:lib",
"//code/utilities/types/sets:lib",
"//code/transcompilers/unilang/bazel_printer:path_to_bazel_path",
])

hcp(name = "path_to_bazel_path", deps = [
    "//code/utilities/types/general:lib",
    "//code/utilities/types/strings/transformers/other:lib",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/types/char:lib",
    "//code/utilities/types/strings/creators:lib",
])

hcp(name = "top_comment_getter", deps = [
"//code/transcompilers/unilang/options/bazel:build_rule_settings",
"//code/transcompilers/unilang/boilerplate_printer/meta_block/sections:meta_copyright_getter",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/strings/creators:lib",
])