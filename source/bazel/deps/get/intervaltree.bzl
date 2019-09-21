load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def intervaltree():
    http_archive(
        name = "intervaltree",
        build_file = "//bazel/deps/build_files:intervaltree.BUILD",
        sha256 = "32dcbabbfbd870dcfb64675b8d47fa6b718d4b87de6ebac9cbdc792d0fc182d4",
        strip_prefix = "intervaltree-e8082c74a6f5c18de99d8b4cc4a55e2e62a1150d",
        urls = [
            "https://github.com/unilang/intervaltree/archive/e8082c74a6f5c18de99d8b4cc4a55e2e62a1150d.tar.gz",
            "https://github.com/ekg/intervaltree/archive/e8082c74a6f5c18de99d8b4cc4a55e2e62a1150d.tar.gz",
        ],
    )
