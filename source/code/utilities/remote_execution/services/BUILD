package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "grpc_glue",
    srcs = ["grpc_glue.cpp"],
    hdrs = ["grpc_glue.hpp"],
    deps = [
        "@com_github_grpc_grpc//:grpc++",
        "@com_github_grpc_grpc//:grpc++_reflection",
        "@remote_apis//:remote_execution_cc_proto",
        "//code/utilities/formats/serialization:protobuf",
    ],
)
