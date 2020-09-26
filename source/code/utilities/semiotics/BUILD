package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "sign_type",
    values = [
        "index",
        "icon",
        "symbol",
    ],
)

enum_cpp(
    name = "sign_reality",
    values = [
        "base",
        "copy",
        "new",
    ],
)

hcp(
    name = "dyadic_sign",
    deps = [
        "//code/utilities/semiotics:sign_type",
    ],
)

hcp(
    name = "triadic_sign",
    deps = [
        "//code/utilities/semiotics:sign_type",
    ],
)
