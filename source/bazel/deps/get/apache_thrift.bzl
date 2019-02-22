load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def apache_thrift():
    http_archive(
        name = "org_apache_thrift",
        build_file = "//bazel/deps/build_files:thrift.BUILD",
        sha256 = "0e324569321a1b626381baabbb98000c8dd3a59697292dbcc71e67135af0fefd",
        strip_prefix = "thrift-0.11.0",
        urls = [
            "https://github.com/unilang/thrift/archive/0.11.0.tar.gz",
            "https://github.com/apache/thrift/archive/0.11.0.tar.gz",
        ],
    )
