package(
    default_visibility = ["//visibility:public"],
)
#load("@build_stack_rules_proto//cpp:cpp_proto_compile.bzl", "cpp_proto_compile")

# Conventions:
# 1. One proto_library rule per .proto file.
# 2. A file named foo.proto will be in a rule named foo_proto.
proto_library(
    name = "hello_proto",
    srcs = ["hello.proto"],
)

cc_proto_library(
    name = "hello_cc_proto",
    deps = [":hello_proto"],
)