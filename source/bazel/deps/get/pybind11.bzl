load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def pybind11():
    http_archive(
        name = "pybind11",
        build_file = "//bazel/deps/build_files:pybind11.BUILD",
        sha256 = "b69e83658513215b8d1443544d0549b7d231b9f201f6fc787a2b2218b408181e",
        urls = [
            "https://github.com/pybind/pybind11/archive/v2.2.4.tar.gz",
        ],
    )
