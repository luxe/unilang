# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def audioFile():
    http_archive(
        name = "AudioFile",
        build_file = "//bazel/deps/AudioFile:build.BUILD",
        sha256 = "aa893a464546b686dd4d2555eafe2a0e9f4a96713328cf6e37603d7e9af02348",
        strip_prefix = "AudioFile-1c77de76f4f396f1019088f3cd9da5141148ee76",
        urls = [
            "https://github.com/Unilang/AudioFile/archive/1c77de76f4f396f1019088f3cd9da5141148ee76.tar.gz",
        ],
    )
