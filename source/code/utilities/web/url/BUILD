package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "url_parser", deps = [
    "@cxx_url//:cxx_url",
    "//code/utilities/types/strings/observers/splitting:lib",
    "//code/utilities/types/vectors/transformers:lib",
])