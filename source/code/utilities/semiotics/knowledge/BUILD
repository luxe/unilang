package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "dyadic_knowledge",
    deps = [
        "//code/utilities/semiotics:dyadic_sign",
    ],
)

hcp(
    name = "triadic_knowledge",
    deps = [
        "//code/utilities/semiotics:triadic_sign",
    ],
)
