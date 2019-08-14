load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def brain_tree():
    http_archive(
        name = "brain_tree",
        build_file = "//bazel/deps/build_files:brain_tree.BUILD",
        sha256 = "8005614ea34ef8ede2d9345cfa36b85579a44ee8b2d420f2bdcb2f7271bce5e8",
        strip_prefix = "BrainTree-8126f735ae91df204682c56b6a314aa0d17107ff",
        urls = [
            "https://github.com/unilang/BrainTree/archive/8126f735ae91df204682c56b6a314aa0d17107ff.tar.gz",
            "https://github.com/arvidsson/BrainTree/archive/8126f735ae91df204682c56b6a314aa0d17107ff.tar.gz",
        ],
    )
