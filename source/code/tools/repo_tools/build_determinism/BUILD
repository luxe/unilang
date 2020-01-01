package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(name = "task_executer", deps = [
    "//code/utilities/shell:lib",
    "//code/utilities/printers:lib",
    "//code/tools/repo_tools/build_determinism/program_options:lib",
    "//code/utilities/bazel:bazel_runner",
    "//code/tools/repo_tools/build_determinism/settings:settings_getter",
    "//code/utilities/filesystem/paths:lib",
    "@bazel//:spawn_proto_cpp",
    "//code/utilities/serialization:protobuf",
    "//code/utilities/json/functions:lib",
    "//code/utilities/filesystem/files/getting:lib",
    "//code/utilities/git-related:lib",
    "//code/tools/repo_tools/build_determinism/data:spawn_pairings",
    "//code/utilities/types/map:lib",
    "//code/tools/repo_tools/build_determinism:spawn_pairer",
    "//code/tools/repo_tools/build_determinism:spawn_pair_determinism_checker",
    "//code/tools/repo_tools/build_determinism:determinism_ab_runner",
    "//code/tools/repo_tools/build_determinism:determinism_problem_getter",
    "//code/tools/repo_tools/build_determinism/data:determinism_problem",
    "//code/utilities/types/vectors/observers:lib",
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

hcp(name = "determinism_ab_runner", deps = [
    "//code/utilities/printers:lib",
    "//code/utilities/bazel:bazel_runner",
    "//code/tools/repo_tools/build_determinism/data:spawn_pairings",
    "//code/tools/repo_tools/build_determinism:spawn_pairer",
    "//code/tools/repo_tools/build_determinism:spawn_pair_determinism_checker",
    "//code/tools/repo_tools/build_determinism/settings:settings",
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