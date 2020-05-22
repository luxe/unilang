package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "method_stamp",
    deps = [
        "method_stamp_value",
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "method_stamp_value",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)
