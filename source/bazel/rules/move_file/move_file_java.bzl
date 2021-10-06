load("//bazel/rules/move_file:move_file.bzl", "move_file")

def move_java_file(name, output_path):
    target_name = name + "_move_file_target"
    file_name = name + ".java"
    move_file(target_name, file_name, output_path)
