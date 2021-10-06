load("//bazel/rules/capnproto:capnp_to_intermediate.bzl", "capnp_to_intermediate")
load("//bazel/rules/capnproto:intermediate_to_cpp.bzl", "intermediate_to_cpp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

def capnp_to_cpp_object(name, deps = []):
    capnp_to_intermediate(name = name)
    intermediate_to_cpp(name = name)

    explicit_result_h_file = name + ".capnp.h"
    explicit_result_cpp_file = name + ".capnp.c++"

    native.cc_library(
        name = name,
        srcs = [explicit_result_cpp_file],
        hdrs = [explicit_result_h_file],
        deps = [
            "@captnproto//:capnp",
        ],
    )
