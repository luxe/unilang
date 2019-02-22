load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def google_benchmark():
    http_archive(
        name = "com_github_google_benchmark",
        sha256 = "5bcaca7bcb700c84ea1282d3dfe0d2af1c9c2c8783e592744ae33605c133478a",
        strip_prefix = "benchmark-d939634b8ce7e0741a79c1c1f22205fae54b375d",
        urls = [
            "https://github.com/unilang/benchmark/archive/d939634b8ce7e0741a79c1c1f22205fae54b375d.tar.gz",
            "https://github.com/google/benchmark/archive/d939634b8ce7e0741a79c1c1f22205fae54b375d.tar.gz",
        ],
    )
