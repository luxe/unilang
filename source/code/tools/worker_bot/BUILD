package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "worker_bot",
    deps = [],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["//code/tools/worker_bot:worker_bot"],
)
