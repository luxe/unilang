package(default_visibility = ["//visibility:public"])

load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/unilang:unilang_to_code.bzl", "unilang_to_code")
load("//bazel/rules/code:code_to_java.bzl", "code_to_java")

unilang_to_code("hello_world")
code_to_java("hello_world")