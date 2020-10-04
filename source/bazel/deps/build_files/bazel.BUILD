package(default_visibility = ["//visibility:public"])

proto_library(
    name = "spawn_proto",
    srcs = ["src/main/protobuf/spawn.proto"],
)

cc_proto_library(
    name = "spawn_proto_cpp",
    deps = [":spawn_proto"],
)

proto_library(
    name = "workspace_log_proto",
    srcs = ["src/main/java/com/google/devtools/build/lib/bazel/debug/workspace_log.proto"],
)

cc_proto_library(
    name = "workspace_log_proto_cpp",
    deps = [":workspace_log_proto"],
)
