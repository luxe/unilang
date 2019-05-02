load("//bazel/cookbook/capnproto:capnp_to_intermediate.bzl", "capnp_to_intermediate")
load("//bazel/cookbook/capnproto:intermediate_to_cpp.bzl", "intermediate_to_cpp")
load("//bazel/cookbook/capnproto:capnp_to_cpp_object.bzl", "capnp_to_cpp_object")
package(
    default_visibility = ["//visibility:public"],
)

capnp_to_cpp_object(name = "main")
