package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "code",
    deps = [
        "//code/tools/transcompilers/hcp-compiler/programatic/data:headers",
        "//code/tools/transcompilers/hcp-compiler/programatic/data:function",
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