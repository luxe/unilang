load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def gperf():
    http_archive(
        name = "gperftools",
        build_file = "//bazel/deps/build_files:gperftools.BUILD",
        sha256 = "1ee8c8699a0eff6b6a203e59b43330536b22bbcbe6448f54c7091e5efb0763c9",
        strip_prefix = "gperftools-2.7",
        urls = [
            "https://github.com/unilang/gperftools/releases/download/gperftools-2.7/gperftools-2.7.tar.gz",
            "https://github.com/gperftools/gperftools/releases/download/gperftools-2.7/gperftools-2.7.tar.gz",
        ],
    )
