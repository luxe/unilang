package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "bazel_rule_exporter", deps = [
"//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/tools/transcompilers/unilang/options/bazel:language_to_build_object",
"//code/tools/transcompilers/unilang/user-frontend/artifact_actions:artifact_guesser",
"//code/tools/transcompilers/unilang/options/bazel:build_rule_settings",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer:package_getter",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer:top_comment_getter",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer:load_getter",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/tools/transcompilers/unilang/contributor:contributor",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer/rule_getter:rule_getter",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel/bazel_printer:build_info_extractor",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transfer_action",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transferer",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/streams/filestreams:lib",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler:file_transferer",
])