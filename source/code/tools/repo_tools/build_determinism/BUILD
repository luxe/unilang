package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(name = "task_executer", deps = [
    "//code/tools/repo_tools/build_determinism/settings:settings_getter",
    "//code/utilities/printers:lib",
    "//code/utilities/git-related/repo_establisher:repo_establisher",
    "//code/utilities/bazel/setup/wrapper:bazel_wrapper_deriver",
    "//code/utilities/bazel/setup/config:bazel_config_deriver",
    "//code/tools/repo_tools/build_determinism:determinism_ab_runner",
    "//code/tools/repo_tools/build_determinism:reporter",
    "//code/tools/repo_tools/build_determinism:subcommand_filter",
    "//code/tools/repo_tools/build_determinism:determinism_problem_getter",
    "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
    "//code/utilities/random:lib",
    "//code/utilities/bazel:bazel_runner",
    "//code/utilities/filesystem/files/moving:lib",
    "//code/tools/repo_tools/build_determinism:file_isolator",
    "//code/tools/repo_tools/build_determinism/scans:scanner",
    "//code/tools/repo_tools/build_determinism/scans:scan_results",
    "//code/tools/repo_tools/build_determinism:scan_utilities",
    "//code/utilities/bazel/setup:bazel_setup_deriver",
    "//code/tools/repo_tools/build_determinism/scans:scan_results_printer",
])

hcp(name = "file_isolator", deps = [
    "//code/tools/repo_tools/build_determinism/settings:settings_getter",
    "//code/utilities/printers:lib",
    "//code/utilities/git-related/repo_establisher:repo_establisher",
    "//code/utilities/bazel/setup/wrapper:bazel_wrapper_deriver",
    "//code/tools/repo_tools/build_determinism:determinism_ab_runner",
    "//code/tools/repo_tools/build_determinism:reporter",
    "//code/tools/repo_tools/build_determinism:subcommand_filter",
    "//code/tools/repo_tools/build_determinism:determinism_problem_getter",
    "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
    "//code/utilities/random:lib",
    "//code/utilities/bazel:bazel_runner",
    "//code/utilities/filesystem/files/moving:lib",
    "//code/utilities/types/strings/observers/path:lib",
])

hcp(name = "scan_utilities", deps = [
    "//code/tools/repo_tools/build_determinism/settings:settings_getter",
    "//code/utilities/printers:lib",
    "//code/utilities/git-related/repo_establisher:repo_establisher",
    "//code/utilities/bazel/setup/wrapper:bazel_wrapper_deriver",
    "//code/tools/repo_tools/build_determinism:determinism_ab_runner",
    "//code/tools/repo_tools/build_determinism:reporter",
    "//code/tools/repo_tools/build_determinism:subcommand_filter",
    "//code/tools/repo_tools/build_determinism:determinism_problem_getter",
    "//code/utilities/random:lib",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
    "//code/utilities/bazel:bazel_runner",
    "//code/utilities/filesystem/files/moving:lib",
])

hcp(name = "spawn_pairer", deps = [
    "@bazel//:spawn_proto_cpp",
    "//code/tools/repo_tools/build_determinism/data:spawn_pairings",
    "//code/utilities/types/map:lib",
])

hcp(name = "spawn_pair_determinism_checker", deps = [
    "@bazel//:spawn_proto_cpp",
    "//code/tools/repo_tools/build_determinism/data:spawn_pairings",
    "//code/tools/repo_tools/build_determinism/data:determinism_pairings",
    "//code/tools/repo_tools/build_determinism/data:determinism_problem",
    "//code/tools/repo_tools/build_determinism:determinism_problem_getter",
    "//code/utilities/types/map:lib",
    "//code/utilities/printers:lib",
])

hcp(name = "build_determinism_documentation_getter", deps = [
    "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
    "//code/tools/transcompilers/unilang/structure/model:structure",
    "//code/utilities/converters:lib",
    "//code/utilities/json/functions:lib",
    "//code/tools/repo_tools/build_determinism/program_options:lib",
    "//code/utilities/documentation:common_documentation_getter",
])

hcp(name = "determinism_problem_getter", deps = [
    "@bazel//:spawn_proto_cpp",
    "//code/tools/repo_tools/build_determinism/data:spawn_pairings",
    "//code/tools/repo_tools/build_determinism/data:determinism_pairings",
    "//code/tools/repo_tools/build_determinism/data:determinism_problem",
    "//code/utilities/types/map:lib",
    "//code/utilities/printers:lib",
])

hcp(name = "subcommand_filter", deps = [
    "@bazel//:spawn_proto_cpp",
    "//code/tools/repo_tools/build_determinism/data:determinism_problem",
    "//code/tools/repo_tools/build_determinism:determinism_problem_getter",
])


hcp(name = "determinism_ab_runner", deps = [
    "//code/utilities/printers:lib",
    "//code/utilities/bazel:bazel_runner",
    "//code/tools/repo_tools/build_determinism/data:spawn_pairings",
    "//code/tools/repo_tools/build_determinism:spawn_pairer",
    "//code/tools/repo_tools/build_determinism:spawn_pair_determinism_checker",
    "//code/tools/repo_tools/build_determinism/settings:settings",
    "//code/utilities/random:lib",
    "//code/utilities/shell:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/types/strings/transformers/removing:lib",
    "//code/utilities/types/strings/observers/path:lib",
])

hcp(name = "reporter", deps = [
    "//code/utilities/shell:lib",
    "//code/utilities/printers:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/vectors/observers:lib",
    "@bazel//:spawn_proto_cpp",
    "//code/tools/repo_tools/build_determinism/data:spawn_pairings",
    "//code/tools/repo_tools/build_determinism/data:determinism_problem",
    "//code/utilities/types/map:lib",
    "//code/tools/repo_tools/build_determinism:spawn_pairer",
    "//code/tools/repo_tools/build_determinism:spawn_pair_determinism_checker",
    "//code/tools/repo_tools/build_determinism:determinism_ab_runner",
    "//code/tools/repo_tools/build_determinism:determinism_problem_getter",
    "//code/tools/repo_tools/build_determinism/settings:report_settings",
    "//code/utilities/types/strings/observers/splitting:lib",
    "//code/utilities/types/strings/observers/path:lib",
    "//code/utilities/types/sets:lib",
    "//code/tools/repo_tools/build_determinism:subcommand_filter",
])


distributable_cpp_main(
    name = "build_determinism",
    deps = [
        "//code/tools/repo_tools/build_determinism:task_executer",
        "//code/tools/repo_tools/build_determinism/program_options:lib",
    ],
    description = "tests build determinism in a repo",
    depends = [
    ],
)
