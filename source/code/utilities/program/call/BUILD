package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/strings/observers/converting:lib",
    ],
)

hcp(
    name = "thread_caller",
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/program/processes:lib",
    ],
)
