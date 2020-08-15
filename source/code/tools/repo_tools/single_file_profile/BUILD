package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

distributable_cpp_main(
    name = "single_file_profile",
    depends = [
    ],
    description = "profile compilation performance of individual cc file",
    deps = [
        "//code/tools/repo_tools/single_file_profile:task_executer",
        "//code/tools/repo_tools/single_file_profile/program_options:lib",
    ],
)

hcp(
    name = "task_executer",
    deps = [
        "//code/tools/repo_tools/single_file_profile/program_options:lib",
    ],
)