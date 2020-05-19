load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def mpmcQueue():
    http_archive(
        name = "mpmc_queue",
        build_file = "//bazel/deps/build_files:mpmc_queue.BUILD",
        sha256 = "675004f332c74390c16efea98f30ebc636a2855434bdbfa24eaa703501a6ae0f",
        strip_prefix = "MPMCQueue-5883e32b07e8a60c22d532d9120ea5c11348aea9",
        urls = [
            "https://github.com/unilang/MPMCQueue/archive/5883e32b07e8a60c22d532d9120ea5c11348aea9.tar.gz",
            "https://github.com/rigtorp/MPMCQueue/archive/5883e32b07e8a60c22d532d9120ea5c11348aea9.tar.gz",
        ],
    )