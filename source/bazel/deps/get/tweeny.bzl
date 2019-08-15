load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def tweeny():
    http_archive(
        name = "tweeny",
        build_file = "//bazel/deps/build_files:tweeny.BUILD",
        sha256 = "449f62da783bc47b2ebe91912183f022967f4f7bf1ccfdebe47ace3528f8c2e7",
        strip_prefix = "tweeny-07afa4d71627030b25b470fff545516d5fc59c47",
        urls = [
            "https://github.com/unilang/tweeny/archive/07afa4d71627030b25b470fff545516d5fc59c47.tar.gz",
            "https://github.com/ mobius3/tweeny/archive/1c2eb4e57246eb42a987eb373e3bc7d1800aa34a.tar.gz",
        ],
    )