load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def andres_graph():
    http_archive(
        name = "andres_graph",
        build_file = "//bazel/deps/build_files:andres_graph.BUILD",
        sha256 = "00432f3007b4cb2a8d6f2e021fd5625a79e307d6532971719ca6ab81dd0ae752",
        strip_prefix = "graph-1.11",
        urls = [
            "https://github.com/unilang/graph/archive/v1.11.tar.gz",
            "https://github.com/bjoern-andres/graph/archive/v1.11.tar.gz",
        ],
    )
