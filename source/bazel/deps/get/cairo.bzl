load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def cairo():
    http_archive(
        name = "cairo",
        build_file = "//bazel/deps/build_files:cairo.BUILD",
        sha256 = "8c90f00c500b2299c0a323dd9beead2a00353752b2092ead558139bd67f7bf16",
        strip_prefix = "cairo-1.14.12",
        urls = [
            "https://www.cairographics.org/releases/cairo-1.14.12.tar.xz",
        ],
    )