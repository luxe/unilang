package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp_hdrs_derive(
    name = "profile_compilation_timer",
    implementation_deps = [
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
    ],
    interface_deps = [
        "//code/utilities/filesystem/paths:lib",
    ],
)

hcp_hdrs_derive(
    name = "branch_profile_compilation_timer",
    implementation_deps = [
        "//code/utilities/build/profiler:profile_compilation_timer",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/program/wrappers/git:branch_switcher",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/types/vectors/converters:lib",
    ],
    interface_deps = [
        "//code/utilities/build/profiler/data:profile_results",
        "//code/utilities/build/profiler/data:profile_settings",
    ],
)
