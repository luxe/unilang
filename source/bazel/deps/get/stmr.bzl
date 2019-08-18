load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def stmr():
    http_archive(
        name = "stmr",
        build_file = "//bazel/deps/build_files:stmr.BUILD",
        sha256 = "90e134d6de671de0faa0a261f3f32945779f612ef0a8294236dcc2d88f00c9a9",
        strip_prefix = "stmr.c-236c5862e534f3426177267da76ea507bc872c9c",
        urls = [
            "https://github.com/unilang/stmr.c/archive/236c5862e534f3426177267da76ea507bc872c9c.tar.gz",
            "https://github.com/mobius3/stmr.c/archive/236c5862e534f3426177267da76ea507bc872c9c.tar.gz",
        ],
    )