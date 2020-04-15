package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

cpp_main(
    name = "knowledge_print",
    deps = [
        "//code/tools/knowledge_print:knowledge_runner",
    ],
)


hcp(name="knowledge_runner", deps = [
    "//code/utilities/program/wrappers/graphviz:graphviz_image_maker",
    "//code/utilities/semiotics/knowledge_builders:traffic_sign",
    "//code/utilities/semiotics:triadic_knowledge",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/filesystem/paths:lib",
])