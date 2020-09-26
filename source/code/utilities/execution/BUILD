package(default_visibility = ["//visibility:public"])

load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/hcp:hcp.bzl", "hcp")

hcp(
    name = "thread_pool_getter",
    deps = ["@boost//:asio"],
)

hcp(
    name = "thread_pool_loop",
    deps = ["@boost//:asio"],
)
