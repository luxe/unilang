load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def HashLib4CPP():
    http_archive(
        name = "HashLib4CPP",
        build_file = "//bazel/deps/build_files:HashLib4CPP.BUILD",
        sha256 = "b2bf7eec9cbe593b16104ffe9e200f51b33fa0e70b10a047cc9c90b17d5aa4ce",
        strip_prefix = "HashLib4CPP-ec6c056df3a9093e731d9a3d60e429554783089e",
        urls = [
            "https://github.com/unilang/HashLib4CPP/archive/ec6c056df3a9093e731d9a3d60e429554783089e.tar.gz",
            "https://github.com/ron4fun/HashLib4CPP/archive/ec6c056df3a9093e731d9a3d60e429554783089e.tar.gz",
        ],
    )
