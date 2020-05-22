load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def gd():
    http_archive(
        name = "gd",
        build_file = "//bazel/deps/build_files:gd.BUILD",
        sha256 = "a66111c9b4a04e818e9e2a37d7ae8d4aae0939a100a36b0ffb52c706a09074b5",
        strip_prefix = "libgd-2.2.5",
        urls = [
            "https://github.com/unilang/libgd/releases/download/gd-2.2.5/libgd-2.2.5.tar.gz",
            "https://github.com/libgd/libgd/releases/download/gd-2.2.5/libgd-2.2.5.tar.gz",
        ],
    )
