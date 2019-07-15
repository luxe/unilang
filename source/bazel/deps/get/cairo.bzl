load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def cairo():
    http_archive(
        name = "cairo",
        build_file = "//bazel/deps/build_files:cairo.BUILD",
        sha256 = "b1d1344b33f72fc239227e58d98acbe500946a520671e239ae3de89c7a72027d",
        strip_prefix = "cairo-cbc241d338ca7bf927a7cfe23cb15c58491373e0",
        urls = [
            "https://github.com/unilang/cairo/archive/cbc241d338ca7bf927a7cfe23cb15c58491373e0.tar.gz",
            "https://github.com/freedesktop/cairo/archive/cbc241d338ca7bf927a7cfe23cb15c58491373e0.tar.gz",
        ],
    )