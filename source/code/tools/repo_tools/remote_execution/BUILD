package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "@remote_apis//:remote_execution_cc_proto",
        "@com_github_grpc_grpc//:grpc++",
        "@com_github_grpc_grpc//:grpc++_reflection",
    ],
)