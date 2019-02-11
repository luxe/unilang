package(
    default_visibility = ["//visibility:public"],
)
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

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [":hello_cc_proto"]
)