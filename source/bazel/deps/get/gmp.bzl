load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def gmp():
    git_repository(
        name = "bazelify_gmp",
        remote = "https://github.com/robin-thomas/bazelify-gmp",
        commit = "bb4881b35e6864c90493980d035e1d984cafd093",
    )
