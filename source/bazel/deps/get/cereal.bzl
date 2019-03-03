load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def cereal():
    http_archive(
        name = "cereal",
        build_file = "//bazel/deps/build_files:cereal.BUILD",
        sha256 = "26361b539fe50eee308b564faa2742166d2922a7ab0bd4870ac55708581228c8",
        strip_prefix = "cereal-51cbda5f30e56c801c07fe3d3aba5d7fb9e6cca4",
        urls = [
            "https://github.com/unilang/cereal/archive/51cbda5f30e56c801c07fe3d3aba5d7fb9e6cca4.tar.gz",
            "https://github.com/USCiLab/cereal/archive/51cbda5f30e56c801c07fe3d3aba5d7fb9e6cca4.tar.gz",
        ],
    )
