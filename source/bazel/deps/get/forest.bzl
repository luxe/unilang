load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def forest():
    http_archive(
        name = "forest",
        build_file = "//bazel/deps/build_files:forest.BUILD",
        sha256 = "d6bbd2ae2f9dd96e0fabb241a1f02ac13524d2e4c2862a953f669431334479c6",
        strip_prefix = "forest-0d09364e1a202d70b0115696558eb8574eca9fe7",
        urls = [
            "https://github.com/unilang/forest/archive/0d09364e1a202d70b0115696558eb8574eca9fe7.tar.gz",
            "https://github.com/xorz57/forest/archive/0d09364e1a202d70b0115696558eb8574eca9fe7.tar.gz",
        ],
    )
