package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "to_graphviz",
    deps = [
        "//code/utilities/program/wrappers/graphviz:graphviz_image_maker",
        "//code/utilities/semiotics/knowledge:dyadic_knowledge",
        "//code/utilities/semiotics/knowledge:triadic_knowledge",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)
