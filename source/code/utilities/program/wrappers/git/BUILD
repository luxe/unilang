package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/call/process_spawn/timed:timed_process_spawner",
        "//code/utilities/random:lib",
        "//code/utilities/random/files:random_files",
        "//code/utilities/types/strings/observers/converting:lib",
    ],
)

hcp_hdrs_derive(
    name = "git_setuper",
    interface_deps = [
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/deps/external/curl:lib",
    ],
)

hcp_hdrs_derive(
    name = "branch_switcher",
    interface_deps = [
        "//code/utilities/program/call:lib",
    ],
)

hcp_hdrs_derive(
    name = "git_upstream_pusher",
    interface_deps = [
        "//code/utilities/program/call:lib",
    ],
)

hcp_hdrs_derive(
    name = "latest_commit_getter",
    interface_deps = [
        "//code/utilities/program/call:lib",
    ],
)

cc_binary(
    name = "setup_git",
    srcs = ["setup_git.cpp"],
    deps = ["//code/utilities/program/wrappers/git:git_setuper"],
)
