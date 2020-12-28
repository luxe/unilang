package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "unilang_to_code",
    srcs = ["main.cpp"],
    deps = [
        "//code/tools/transcompilers/unilang/unilang_to_code/program_options:lib",
    ],
)
