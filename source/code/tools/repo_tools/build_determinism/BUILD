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