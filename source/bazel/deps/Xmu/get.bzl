# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def xmu():
    http_archive(
        name = "Xmu",
        build_file = "//bazel/deps/Xmu:build.BUILD",
        sha256 = "f7967206f463472f6c86fa0816aa8f85192cfd179cfed8b0fa728799d3816c1d",
        strip_prefix = "libXmu-4459e6940fe3fdf26a8d5d4c71989498bc400a62",
        urls = [
            "https://github.com/Unilang/libXmu/archive/4459e6940fe3fdf26a8d5d4c71989498bc400a62.tar.gz",
        ],
        patches = [
            "//bazel/deps/Xmu/patches:p1.patch",
        ],
        patch_args = [
            "-p1",
        ],
    )
