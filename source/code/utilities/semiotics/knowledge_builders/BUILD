package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "traffic_sign_dyadic",
    deps = [
        "//code/utilities/semiotics/knowledge:dyadic_knowledge",
    ],
)

hcp(
    name = "traffic_sign_triadic",
    deps = [
        "//code/utilities/semiotics/knowledge:triadic_knowledge",
    ],
)
