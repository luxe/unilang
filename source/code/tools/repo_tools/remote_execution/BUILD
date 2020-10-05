package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "@com_github_grpc_grpc//:grpc++",
        "@com_github_grpc_grpc//:grpc++_reflection",
        "@remote_apis//:remote_execution_cc_proto",
        "//code/utilities/formats/serialization:protobuf",
        "//code/tools/repo_tools/remote_execution/server:server_settings",
    ],
)
