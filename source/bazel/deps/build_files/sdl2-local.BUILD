package(default_visibility = ["//visibility:public"])
load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

cc_library(
    name = "SDL2",
    hdrs = glob(["include/SDL2/*.h"]),
    defines = ["_REENTRANT"],
    includes = ["include/SDL2"],
    linkopts = ["-lSDL2", "-lSDL2_mixer"],
    visibility = ["//visibility:public"],
)
