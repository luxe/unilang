# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def flatBuffers():
    http_archive(
        name = "flat_buffers",
        build_file = "//bazel/deps/flat_buffers:build.BUILD",
        sha256 = "c6a6ce90c75c76ae0d05f16864df499d8cc9c00dbfc456ae08f5ae60d61bd3e4",
        strip_prefix = "flatbuffers-db972be264078bf83e112836c0b685a7020e96b8",
        urls = [
            "https://github.com/Unilang/flatbuffers/archive/db972be264078bf83e112836c0b685a7020e96b8.tar.gz",
        ],
    )
