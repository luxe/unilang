load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def fontconfig():
    http_archive(
        name = "fontconfig",
        build_file = "//bazel/deps/build_files:fontconfig.BUILD",
        sha256 = "711f7fe1c4604f2d0cd8397d18ed70dede07b86a6057009b790395a8f91f558c",
        strip_prefix = "fontconfig-277eca11e8f619498e6123001f22bd33d1674df2",
        urls = [
            "https://github.com/unilang/fontconfig/archive/277eca11e8f619498e6123001f22bd33d1674df2.tar.gz",
            "https://github.com/freedesktop/fontconfig/archive/2960391699ab3b417a17a0a2ac29e97e9c3d3c99.tar.gz",
        ],
    )
