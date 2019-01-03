package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "hidl", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/bazel:build_rule_settings",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/char:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/bazel_printer:path_to_bazel_path",
"//code/transcompilers/unilang/bazel_printer:target_name_deriver",
"//code/transcompilers/unilang/bazel_printer:deps_printer",
])

hcp(name = "config_hidl", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/bazel:build_rule_settings",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/char:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/bazel_printer:path_to_bazel_path",
"//code/transcompilers/unilang/bazel_printer:target_name_deriver",
"//code/transcompilers/unilang/bazel_printer:deps_printer",
])

hcp(name = "cc_library", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/bazel:build_rule_settings",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/char:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/bazel_printer:path_to_bazel_path",
"//code/transcompilers/unilang/bazel_printer:target_name_deriver",
"//code/transcompilers/unilang/bazel_printer:deps_printer",
])

hcp(name = "rule_getter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/bazel:build_rule_settings",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/char:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/structure:inlined_structures",
"//code/transcompilers/unilang/bazel_printer:build_info_extractor",
"//code/transcompilers/unilang/bazel_printer/rule_getter:hidl",
"//code/transcompilers/unilang/bazel_printer/rule_getter:config_hidl",
"//code/transcompilers/unilang/bazel_printer/rule_getter:cc_library",
])