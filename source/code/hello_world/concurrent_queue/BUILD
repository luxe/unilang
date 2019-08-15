load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "blocking",
    deps = [
        "@concurrent_queue//:concurrent_queue",
    ],
)