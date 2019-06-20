load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "two_inf",
)

cpp_main(
    name = "boost_thread_pool",
    deps = ["@boost//:asio",]
)