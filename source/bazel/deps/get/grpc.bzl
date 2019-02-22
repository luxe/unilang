load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def grpc():
    http_archive(
        name = "com_github_grpc_grpc",
        sha256 = "d99db0b39b490d2469a8ef74197d5f211fa740fc9581dccecbb76c56d080fce1",
        strip_prefix = "grpc-1.16.0",
        urls = [
            "https://github.com/unilang/grpc/archive/v1.16.0.tar.gz",
            "https://github.com/grpc/grpc/archive/v1.16.0.tar.gz",
        ],
    )
