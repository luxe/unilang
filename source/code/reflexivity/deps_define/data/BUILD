package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(name = "dependency_specifications", deps = [
    "//code/reflexivity/deps_define/data:dependency_specification"
])
hcp(name = "dependency_specification", deps = [
])