package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "timed_process_results",
    deps = [
        "//code/utilities/program/call/process_spawn:process_results",
    ],
)

hcp(
    name = "timed_process_spawner",
    deps = [
        "//code/utilities/program/call/process_spawn:process_results",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/program/call/process_spawn/timed:timed_process_results",
    ],
)
