load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def fmt():
    http_archive(
        name = "fmt",
        build_file = "//bazel/deps/build_files:fmt.BUILD",
        sha256 = "3c812a18e9f72a88631ab4732a97ce9ef5bcbefb3235e9fd465f059ba204359b",
        strip_prefix = "fmt-5.2.1",
        urls = [
            "https://github.com/fmtlib/fmt/archive/5.2.1.tar.gz",
        ],
    )
