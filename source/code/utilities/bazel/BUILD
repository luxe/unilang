package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")


hcp(name = "bazel_runner", deps = [
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/types/strings/transformers/removing:lib",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/shell:lib",
    "//code/utilities/random:lib",
    "@bazel//:spawn_proto_cpp",
    "//code/utilities/serialization:protobuf",
    "//code/utilities/json/functions:lib",
])