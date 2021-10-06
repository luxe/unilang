# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def utilsLinux():
    http_archive(
        name = "utilsLinux",
        build_file = "//bazel/deps/utilsLinux:build.BUILD",
        sha256 = "902dba36dfcf50d15e86d0d3cdbb513e57cd455231c3c9a08ac563c6e23e66a8",
        strip_prefix = "util-linux-2eb527722af2093038bf38d4554c086d20df79c9",
        urls = [
            "https://github.com/Unilang/util-linux/archive/2eb527722af2093038bf38d4554c086d20df79c9.tar.gz",
        ],
    )
