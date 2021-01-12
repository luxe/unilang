load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/unilang:unilang_to_code.bzl", "unilang_to_code")
load("//bazel/rules/code:code_to_java.bzl", "code_to_java")
load("//bazel/rules/move_file:move_file.bzl", "move_file")
load("//bazel/rules/move_file:move_file_java.bzl", "move_java_file")

def unilang_to_java(name):
    unilang_to_code(name)
    code_to_java(name)