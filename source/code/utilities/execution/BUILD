package(default_visibility = ["//visibility:public"])

load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

hcp_hdrs_derive(
    name = "thread_pool_getter",
    interface_deps = [
        "//code/utilities/deps/external/boost/asio:lib",
        "//code/utilities/deps/stl/thread:lib",
    ],
)

hcp_hdrs_derive(
    name = "thread_pool_loop",
    interface_deps = [
        "//code/utilities/deps/external/boost/asio:lib",
        "//code/utilities/deps/stl/thread:lib",
    ],
)
