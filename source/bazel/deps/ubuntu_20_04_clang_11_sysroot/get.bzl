# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def ubuntu2004Clang11Sysroot():
    http_archive(
        name="ubuntu_20_04_clang_11_sysroot" ,
        build_file="//bazel/deps/ubuntu_20_04_clang_11_sysroot:build.BUILD" ,
        sha256="4d07d996b2fdd1381c3f1b940cf9d4a6bc9abb3923b7759672f8c47e2c165702" ,
        strip_prefix="ubuntu_20_04_clang_11_sysroot-be13d45d482ae05a0a6794fb71cb31b7e24bc90c" ,
        urls = [
            "https://github.com/Unilang/ubuntu_20_04_clang_11_sysroot/archive/be13d45d482ae05a0a6794fb71cb31b7e24bc90c.tar.gz",
        ],
    )
