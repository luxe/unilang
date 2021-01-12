load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/unilang:unilang_to_java.bzl", "unilang_to_java")
load("//bazel/rules/code:code_to_java.bzl", "code_to_java")
load("//bazel/rules/move_file:move_file.bzl", "move_file")
load("//bazel/rules/move_file:move_file_java.bzl", "move_java_file")

def transfer_unilang_java(name,path):
    unilang_to_java(name)
    move_java_file(name,path)