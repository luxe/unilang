load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def threadpool():
    http_archive(
        name = "threadpool",
        build_file = "//bazel/deps/build_files:threadpool.BUILD",
        sha256 = "44e7d6de0ef5380b86dfea74bbd53545319cdc06a50d7a1095b04d8a949242c2",
        strip_prefix = "threadpool-06e635dff22c9d359dfb93bc535a460774dc7319",
        urls = [
            "https://github.com/unilang/threadpool/archive/06e635dff22c9d359dfb93bc535a460774dc7319.tar.gz",
            "https://github.com/reyreaud-l/threadpool/archive/06e635dff22c9d359dfb93bc535a460774dc7319.tar.gz",
        ],
    )
