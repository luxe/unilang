#load("//bazel/cookbook/protobuf:cpp.bzl", "cpp_proto_object")
package(default_visibility = ["//visibility:public"])


proto_library(
   name = "spawn_proto",
   srcs = ["spawn.proto"],
)
cc_proto_library(
    name = "spawn_proto_cpp",
    deps = [":spawn_proto"],
)