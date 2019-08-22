load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def x11():
    http_archive(
        name = "x11",
        build_file = "//bazel/deps/build_files:x11.BUILD",
        sha256 = "f57a916500625261239fdbb0d712aaa2aff0c45c562634b2977164f41895cc57",
        strip_prefix = "libX11-edc7680ed5a03cedb5facf14693823455e12c29c",
        urls = [
            "https://github.com/unilang/libX11/archive/edc7680ed5a03cedb5facf14693823455e12c29c.tar.gz",
            "https://github.com/mirror/libX11/archive/edc7680ed5a03cedb5facf14693823455e12c29c.tar.gz",
        ],
    )
