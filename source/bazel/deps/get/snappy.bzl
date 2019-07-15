load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def snappy():
    http_archive(
        name = "snappy",
        build_file = "//bazel/deps/build_files:snappy.BUILD",
        patches = ["//bazel/deps/build_files:snappy.patch"],
        sha256 = "3dfa02e873ff51a11ee02b9ca391807f0c8ea0529a4924afa645fbf97163f9d4",
        strip_prefix = "snappy-1.1.7",
        urls = [
            "https://github.com/unilang/snappy/archive/1.1.7.tar.gz",
            "https://github.com/google/snappy/archive/1.1.7.tar.gz",
        ],
    )
