load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def nasm():
    http_archive(
        name = "nasm",
        build_file = "//bazel/deps/build_files:nasm.BUILD",
        sha256 = "d3e1949883f77d631e256523c0e77098cf6ffd7eda1489a99d9f09fcd7225d95",
        strip_prefix = "nasm-e91f5cc1322eed4da0de81656276e021bf352c3d",
        urls = [
            "https://github.com/unilang/nasm/archive/e91f5cc1322eed4da0de81656276e021bf352c3d.tar.gz",
            "https://github.com/sezero/nasm/archive/e91f5cc1322eed4da0de81656276e021bf352c3d.tar.gz",
        ],
    )