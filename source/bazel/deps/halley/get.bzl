# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/reflexive_refresh

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def halley():
    http_archive(
        name = "halley",
        build_file = "//bazel/deps/halley:build.BUILD",
        sha256 = "f4ff28208cb144e60ac2233dfbcf495ea3c7627e9accb74804511191b31aff99",
        strip_prefix = "halley-cd90859ed700b65bbab0f4473c7e2ce9ee4cd65f",
        urls = [
            "https://github.com/Unilang/halley/archive/cd90859ed700b65bbab0f4473c7e2ce9ee4cd65f.tar.gz",
        ],
    )