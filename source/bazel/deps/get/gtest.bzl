load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def gtest():
    http_archive(
        name = "com_google_googletest",
        sha256 = "3efbb860886c6018d707f1b5ee3e84d4ef63517ee85744aa2a8cb12b2feef57b",
        strip_prefix = "googletest-e5e2ef7cd27cc089c1d8302a11970ef870554294",
        urls = [
            "https://github.com/unilang/googletest/archive/e5e2ef7cd27cc089c1d8302a11970ef870554294.tar.gz",
            "https://github.com/google/googletest/archive/e5e2ef7cd27cc089c1d8302a11970ef870554294.tar.gz",
        ],
    )
