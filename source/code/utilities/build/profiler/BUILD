package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

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

hcp(
    name = "branch_profile_compilation_timer",
    deps = [
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/build/profiler:profile_compilation_timer",
        "//code/utilities/program/wrappers/git:branch_switcher",
        "//code/utilities/build/profiler/data:profile_settings",
        "//code/utilities/build/profiler/data:profile_results",
    ],
)
