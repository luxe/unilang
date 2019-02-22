load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def curl():
    http_archive(
        name = "curl",
        build_file = "//bazel/deps/build_files:curl.BUILD",
        patches = ["//bazel/deps/build_files:curl.patch"],
        sha256 = "55ccd5b5209f8cc53d4250e2a9fd87e6f67dd323ae8bd7d06b072cfcbb7836cb",
        strip_prefix = "curl-7.62.0",
        urls = [
            "https://github.com/curl/curl/releases/download/curl-7_62_0/curl-7.62.0.tar.gz",
        ],
    )
