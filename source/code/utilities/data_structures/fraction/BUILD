package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "fraction")

hcp(
    name = "fraction_parser",
    deps = [
        "//code/utilities/data_structures/fraction",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
    ],
)
