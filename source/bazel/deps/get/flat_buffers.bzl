load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def flatBuffers():
    http_archive(
        name = "flatbuffers",
        sha256 = "3f4a286642094f45b1b77228656fbd7ea123964f19502f9ecfd29933fd23a50b",
        strip_prefix = "flatbuffers-1.11.0",
        urls = [
            "https://github.com/unilang/flatbuffers/archive/v1.11.0.tar.gz",
            "https://github.com/google/flatbuffers/archive/v1.11.0.tar.gz",
        ],
    )
