load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def cli11():
    http_archive(
        name = "CLI11",
        build_file = "//bazel/deps/build_files:CLI11.BUILD",
        sha256 = "5ce138794b28b48717101cd57aea70382cb14b8d9859c403fbca1dc5ada0101e",
        strip_prefix = "CLI11-1.6.2",
        urls = [
            "https://github.com/unilang/CLI11/archive/v1.6.2.tar.gz",
            "https://github.com/CLIUtils/CLI11/archive/v1.6.2.tar.gz",
        ],
    )
