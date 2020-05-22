package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "function_body",
    deps = [
        "//code/tools/transcompilers/unilang/structure/model/sections/method/body/body-ast:root_body_element",
        "@boost//:variant",
    ],
)
