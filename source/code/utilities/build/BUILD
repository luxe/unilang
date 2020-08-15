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

hcp(
    name = "profile_compilation_timer",
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/other_language:lib",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
    ],
)

cpp_main(
    name = "build_everything",
    deps = ["//code/utilities/build:self_builder"],
)


