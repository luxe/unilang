load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def fontconfig():
    http_archive(
        name = "fontconfig",
        build_file = "//bazel/deps/build_files:fontconfig.BUILD",
        sha256 = "b97b4f40776e3de517b155085c17822add32ecfe2d557bc1ab16f3b2f5588b02",
        strip_prefix = "fontconfig-2960391699ab3b417a17a0a2ac29e97e9c3d3c99",
        urls = [
            "https://github.com/unilang/fontconfig/archive/2960391699ab3b417a17a0a2ac29e97e9c3d3c99.tar.gz",
            "https://github.com/freedesktop/fontconfig/archive/2960391699ab3b417a17a0a2ac29e97e9c3d3c99.tar.gz",
        ],
    )
