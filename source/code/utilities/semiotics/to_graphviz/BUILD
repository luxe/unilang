package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "to_graphviz", deps = [
    "//code/utilities/program/wrappers/graphviz:graphviz_image_maker",
    "//code/utilities/semiotics:triadic_knowledge",
    "//code/utilities/semiotics:dyadic_knowledge",
    "//code/utilities/types/strings/transformers/appending:lib",
])