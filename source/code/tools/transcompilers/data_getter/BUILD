package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "data_getter",
    srcs = ["main.cpp"],
    deps = [
        "//code/tools/transcompilers/data_getter/program_options:lib",
        "//code/tools/transcompilers/hcp-compiler/programatic/data:code",
        "//code/tools/transcompilers/hcp-compiler/programatic:code_getter",
    ],
)
