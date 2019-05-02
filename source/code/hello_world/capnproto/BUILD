load("//bazel/cookbook/capnproto:capnp_to_intermediate.bzl", "capnp_to_intermediate")
load("//bazel/cookbook/capnproto:intermediate_to_cpp.bzl", "intermediate_to_cpp")
package(
    default_visibility = ["//visibility:public"],
)

capnp_to_intermediate(name = "main")
intermediate_to_cpp(name = "main")

cc_library(
    name = "main",
    srcs = ["main.capnp.c++"],
    hdrs = ["main.capnp.h"],
    deps = [
        "@captnproto//:capnp"
    ]
)
