#load("//bazel/cookbook/protobuf:cpp.bzl", "cpp_proto_object")

# cpp_proto_object(
#     name = "src/main/protobuf/spawn.proto"
# )


proto_library(
   name = "spawn_proto",
   srcs = ["src/main/protobuf/spawn.proto"],
)
cc_proto_library(
    name = "spawn_proto_cpp",
    deps = [":spawn_proto"],
)