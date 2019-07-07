load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def getch():
    http_archive(
        name = "getch",
        build_file = "//bazel/deps/build_files:getch.BUILD",
        sha256 = "38f05f2e3d7db2440227a9f55ae0e979a983559ae107d8db6392668ebb81b12d",
        strip_prefix = "simple-getch-16c0dc6b00c4decb71b82b26ff082ead236a0058",
        urls = [
            "https://github.com/unilang/simple-getch/archive/16c0dc6b00c4decb71b82b26ff082ead236a0058.tar.gz",
            "https://github.com/mouuff/simple-getch/archive/e86fb3d42e290de31995849025e3474b714d35c7.tar.gz",
        ],
    )