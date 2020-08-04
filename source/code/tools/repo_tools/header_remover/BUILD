package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/tools/repo_tools/header_remover/program_options:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/other_language:lib",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/streams/filestreams/write_all:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
    ],
)

distributable_cpp_main(
    name = "header_remover",
    depends = [
    ],
    description = "removes headers from file",
    deps = [
        "//code/tools/repo_tools/header_remover:task_executer",
        "//code/tools/repo_tools/header_remover/program_options:lib",
    ],
)
