package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "hidl", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/bazel:build_rule_settings",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/char:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer:path_to_bazel_path",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer:target_name_deriver",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer:deps_printer",
])

hcp(name = "config_hidl", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/bazel:build_rule_settings",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/char:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer:path_to_bazel_path",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer:target_name_deriver",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer:deps_printer",
])

hcp(name = "cc_library", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/bazel:build_rule_settings",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/char:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer:path_to_bazel_path",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer:target_name_deriver",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer:deps_printer",
])

hcp(name = "rule_getter", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/bazel:build_rule_settings",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/char:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer:build_info_extractor",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer/rule_getter:hidl",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer/rule_getter:config_hidl",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer/rule_getter:cc_library",
])