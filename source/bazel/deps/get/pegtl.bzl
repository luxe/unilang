load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def pegtl():
    http_archive(
        name = "pegtl",
        build_file = "//bazel/deps/build_files:pegtl.BUILD",
        sha256 = "1d0b85f514d65cfdc2e9e177dafa56bc0af01859d3f24a7224f0680b55a1953d",
        strip_prefix = "PEGTL-697aaa06564c6ea9d13f95de081a2d2d46b39160",
        urls = [
            "https://github.com/unilang/PEGTL/archive/697aaa06564c6ea9d13f95de081a2d2d46b39160.tar.gz",
            "https://github.com/taocpp/PEGTL/archive/697aaa06564c6ea9d13f95de081a2d2d46b39160.tar.gz",
        ],
    )
