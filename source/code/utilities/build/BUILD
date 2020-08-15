package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(
    name = "self_builder",
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/program/call/process_spawn/timed:timed_process_results",
        "//code/utilities/program/call/process_spawn/timed:timed_process_spawner",
    ],
)

cpp_main(
    name = "build_everything",
    deps = ["//code/utilities/build:self_builder"],
)


