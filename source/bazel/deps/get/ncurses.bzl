load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def ncurses():
    http_archive(
        name = "ncurses",
        build_file = "//bazel/deps/build_files:ncurses.BUILD",
        sha256 = "bf8ecc53920e2c61fc48d3053075ab437d5a35e4d6a2a2eb111e812bb391fa3b",
        strip_prefix = "ncurses-6.1",
        urls = [
            "https://github.com/unilang/ncurses/archive/v6.1.tar.gz",
            "https://github.com/mirror/ncurses/archive/v6.1.tar.gz",
        ],
    )