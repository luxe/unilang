package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "csv_extractor", deps = [
"@csv//:csv",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/types/strings/transformers/removing:lib",
])