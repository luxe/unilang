# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def bazelGazelle():
    http_archive(
        name = "bazel_gazelle",
        sha256 = "079e615ddbbcd53a0a730341dfe5d52dcc06771bcf782254eb6fd581ec20b102",
        strip_prefix = "bazel-gazelle-2f9261b27f1d2660e2952bc9a0e79e4e81691afe",
        urls = [
            "https://github.com/Unilang/bazel-gazelle/archive/2f9261b27f1d2660e2952bc9a0e79e4e81691afe.tar.gz",
        ],
    )
