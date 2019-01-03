package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "bazel_rule_exporter", deps = [
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/options/bazel:language_to_build_object",
"//code/transcompilers/unilang/user-frontend:language_guesser",
"//code/transcompilers/unilang/options/bazel:build_rule_settings",
"//code/transcompilers/unilang/bazel_printer:package_getter",
"//code/transcompilers/unilang/bazel_printer:top_comment_getter",
"//code/transcompilers/unilang/bazel_printer:load_getter",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/bazel_printer/rule_getter:rule_getter",
"//code/transcompilers/unilang/bazel_printer:build_info_extractor",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transfer_action",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transferer",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/streams/filestreams:lib",
"//code/transcompilers/unilang/f2si_frontend_compiler:file_transferer",
])