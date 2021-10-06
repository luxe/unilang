package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

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
