package(default_visibility = ["//visibility:public"])
load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

cc_library(
    name = "SFML",
    #hdrs = glob(["include/SFML/**/*.hpp"]),
    #defines = ["SFML_STATIC"],
    #includes = ["include/SFML"],
    linkopts = ["-lsfml-window", "-lsfml-graphics", "-lsfml-system"],
    #linkopts = ["-L/usr/lib/x86_64-linux-gnu", "-L/usr/local/lib", "-lpthread", "-lsfml-window", "-lsfml-graphics", "-lsfml-system", "-lsfml-audio"],
    visibility = ["//visibility:public"], 	
)
