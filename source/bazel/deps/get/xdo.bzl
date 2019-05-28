load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def xdo():
    http_archive(
        name = "xdo",
        build_file = "//bazel/deps/build_files:xdo.BUILD",
        sha256 = "b661229f0457939d3867cca1664c5671ae959b309feb58abe9142229c8c7ffb4",
        strip_prefix = "xdo-0.5.7",
        urls = [
            "https://github.com/unilang/xdo/archive/0.5.7.tar.gz",
            "https://github.com/baskerville/xdo/archive/0.5.7.tar.gz",
        ],
    )
