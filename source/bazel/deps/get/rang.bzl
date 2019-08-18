load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def rang():
    http_archive(
        name = "rang",
        build_file = "//bazel/deps/build_files:rang.BUILD",
        sha256 = "1f1cdf9016af45fbb37c8992041547c8ccc1edf2fc04d121d86c894c0e45a8b1",
        strip_prefix = "rang-cabe04d6d6b05356fa8f9741704924788f0dd762",
        urls = [
            "https://github.com/unilang/rang/archive/cabe04d6d6b05356fa8f9741704924788f0dd762.tar.gz",
            "https://github.com/agauniyal/rang/archive/cabe04d6d6b05356fa8f9741704924788f0dd762.tar.gz",
        ],
    )
