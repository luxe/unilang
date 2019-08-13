load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def pthreadpool():
    http_archive(
        name = "pthreadpool",
        build_file = "//bazel/deps/build_files:pthreadpool.BUILD",
        sha256 = "7a523b439a996e2f4376169279409059101f2f71eed4fcc915971368990504a0",
        strip_prefix = "pthreadpool-6673a4c71fe35e077c6843a74017d9c25610c537",
        urls = [
            "https://github.com/unilang/pthreadpool/archive/6673a4c71fe35e077c6843a74017d9c25610c537.tar.gz",
            "https://github.com/Maratyszcza/pthreadpool/archive/6673a4c71fe35e077c6843a74017d9c25610c537.tar.gz",
        ],
    )
