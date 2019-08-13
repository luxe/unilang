load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def fp16():
    http_archive(
        name = "fp16",
        build_file = "//bazel/deps/build_files:fp16.BUILD",
        sha256 = "3e71681e0a67cd28552aa0bbb78ec6a6bd238216df15336dc1326280f7958de2",
        strip_prefix = "FP16-febbb1c163726b5db24bed55cc9dc42529068997",
        urls = [
            "https://github.com/unilang/FP16/archive/febbb1c163726b5db24bed55cc9dc42529068997.tar.gz",
            "https://github.com/Maratyszcza/FP16/archive/febbb1c163726b5db24bed55cc9dc42529068997.tar.gz",
        ],
    )
