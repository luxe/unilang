package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/tools/repo_tools/bazel_network_sync/program_options:lib",
        "//code/utilities/build/build_repo_establisher:build_repo_establisher",
        "//code/utilities/program/wrappers/strace:network_ip_getter",
    ],
)

distributable_cpp_main(
    name = "bazel_network_sync",
    depends = [
    ],
    description = "run bazel sync under strace to extract network ips used",
    deps = [
        "//code/tools/repo_tools/bazel_network_sync:task_executer",
        "//code/tools/repo_tools/bazel_network_sync/program_options:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "bazel_network_sync_documentation_getter",
    deps = [
        "//code/tools/repo_tools/bazel_network_sync/program_options:lib",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/utilities/documentation:common_documentation_getter",
        "//code/utilities/formats/json/functions:lib",
        "//code/utilities/types/converters:lib",
    ],
)
