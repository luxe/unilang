load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def fxDiv():
    http_archive(
        name = "fx_div",
        build_file = "//bazel/deps/build_files:fx_div.BUILD",
        sha256 = "7d3215bea832fe77091ec5666200b91156df6724da1e348205078346325fc45e",
        strip_prefix = "FXdiv-f8c5354679ec2597792bc70a9e06eff50c508b9a",
        urls = [
            "https://github.com/unilang/FXdiv/archive/f8c5354679ec2597792bc70a9e06eff50c508b9a.tar.gz",
            "https://github.com/Maratyszcza/FXdiv/archive/f8c5354679ec2597792bc70a9e06eff50c508b9a.tar.gz",
        ],
    )
