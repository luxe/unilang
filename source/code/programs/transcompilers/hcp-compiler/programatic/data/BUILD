package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "code",
    deps = [
        "//code/programs/transcompilers/hcp-compiler/programatic/data:function",
        "//code/programs/transcompilers/hcp-compiler/programatic/data:headers",
    ],
)

hcp(
    name = "headers",
    deps = [
    ],
)

hcp(
    name = "function",
    deps = [
    ],
)
