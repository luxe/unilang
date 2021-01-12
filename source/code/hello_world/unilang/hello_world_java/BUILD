package(default_visibility = ["//visibility:public"])

load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/unilang:unilang_to_code.bzl", "unilang_to_code")
load("//bazel/rules/code:code_to_java.bzl", "code_to_java")
load("//bazel/rules/move_file:move_file.bzl", "move_file")
load("//bazel/rules/move_file:move_file_java.bzl", "move_java_file")

unilang_to_code("hello_world")
code_to_java("hello_world")
move_java_file("hello_world","/home/luxe/Desktop/output_test/THIsdfsdfS_IS_A_TEST.java")