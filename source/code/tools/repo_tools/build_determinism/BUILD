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
])

hcp(name = "spawn_pairer", deps = [
    "@bazel//:spawn_proto_cpp",
    "//code/tools/repo_tools/build_determinism/data:spawn_pairings",
    "//code/utilities/types/map:lib",
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