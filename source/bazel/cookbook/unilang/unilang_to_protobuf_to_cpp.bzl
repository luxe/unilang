load("//bazel/cookbook/unilang:unilang_to_protobuf.bzl", "unilang_to_protobuf")
load("//bazel/cookbook/protobuf:cpp.bzl", "cpp_proto_object")

def unilang_to_protobuf_to_cpp(name, deps = []):
    unilang_to_protobuf(name, deps)
    cpp_proto_object(name, deps)
