package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "worker_bot",
    deps = [
        "//code/utilities/filesystem/paths:lib"
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["//code/tools/worker_bot:worker_bot",
            "//code/utilities/program/call:lib"],
)
