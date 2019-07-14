load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def pixman():
    http_archive(
        name = "pixman",
        build_file = "//bazel/deps/build_files:pixman.BUILD",
        patches = ["//bazel/deps/build_files:pixman.patch"],
        sha256 = "2836d25566d8bd87af3d6a8bb6079248852d1488b2984c03872989749355e7ac",
        strip_prefix = "pixman-30d907c714035fbf67ddc3696e868fb670688b5b",
        urls = [
            "https://github.com/unilang/pixman/archive/30d907c714035fbf67ddc3696e868fb670688b5b.tar.gz",
            "https://github.com/servo/pixman/archive/958bd334b3c17f529c80f2eeef4224f45c62f292.tar.gz",
            "https://www.cairographics.org/releases/pixman-0.34.0.tar.gz",
        ],
    )