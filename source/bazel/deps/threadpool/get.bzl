# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def threadpool():
    http_archive(
        name = "threadpool",
        build_file = "//bazel/deps/threadpool:build.BUILD",
        sha256 = "44e7d6de0ef5380b86dfea74bbd53545319cdc06a50d7a1095b04d8a949242c2",
        strip_prefix = "threadpool-06e635dff22c9d359dfb93bc535a460774dc7319",
        urls = [
            "https://github.com/Unilang/threadpool/archive/06e635dff22c9d359dfb93bc535a460774dc7319.tar.gz",
        ],
    )
