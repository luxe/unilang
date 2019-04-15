load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
load("//bazel/cookbook/protobuf:cpp.bzl", "cpp_proto_object")
package(
    default_visibility = ["//visibility:public"],
)

cpp_proto_object(
  name = "hello"
)

cpp_main(
    name = "main",
    deps = [":hello_cpp_proto"]
)