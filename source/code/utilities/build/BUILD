package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(name="self_builder", deps = [
    "//code/utilities/program/call/process_spawn:process_spawner",
    "//code/utilities/filesystem/paths:lib",
])

cpp_main(
  name = "build_everything",
  deps = ["//code/utilities/build:self_builder"]
)