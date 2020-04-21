package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "process_results", deps = [
])

hcp(name = "process_spawner", deps = [
    "//code/utilities/streams/pstreams:lib",
    "//code/utilities/program/call/process_spawn:process_results",
])