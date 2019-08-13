load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def gmp():
    # http_archive(
    #     name = "bazelify_gmp",
    #     #build_file = "//bazel/deps/build_files:gmp.BUILD",
    #     sha256 = "677d6857060147ccd008bd7440ce730047f89865985f8e47c6e2dc84859c49f5",
    #     strip_prefix = "bazelify-gmp-bb4881b35e6864c90493980d035e1d984cafd093",
    #     urls = [
    #         "https://github.com/unilang/bazelify-gmp/archive/bb4881b35e6864c90493980d035e1d984cafd093.tar.gz",
    #         "https://github.com/robin-thomas/bazelify-gmp/archive/bb4881b35e6864c90493980d035e1d984cafd093.tar.gz",
    #     ],
    # )
    git_repository(
        name = "bazelify_gmp",
        remote = "https://github.com/robin-thomas/bazelify-gmp",
        commit = "bb4881b35e6864c90493980d035e1d984cafd093",
    )
