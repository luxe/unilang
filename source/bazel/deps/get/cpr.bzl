load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def cpr():
    http_archive(
        name = "cpr",
        build_file = "//bazel/deps/build_files:cpr.BUILD",
        patches = ["//bazel/deps/build_files:cpr.patch"],
        sha256 = "82597627e8b2aef1f0482631c9b11595c63a7565bb462a5995d126da4419ac99",
        strip_prefix = "cpr-1.3.0",
        urls = [
            "https://github.com/unilang/cpr/archive/1.3.0.tar.gz",
            "https://github.com/whoshuu/cpr/archive/1.3.0.tar.gz",
        ],
    )
