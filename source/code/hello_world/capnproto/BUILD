load("//bazel/cookbook/capnproto:capnp_to_immediate.bzl", "capnp_to_immediate")
load("//bazel/cookbook/capnproto:immediate_to_cpp.bzl", "immediate_to_cpp")
package(
    default_visibility = ["//visibility:public"],
)

capnp_to_immediate(name = "main")
immediate_to_cpp(name = "main")
