load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def spdlog():
    http_archive(
        name = "spdlog",
        build_file = "//bazel/deps/build_files:spdlog.BUILD",
        sha256 = "160845266e94db1d4922ef755637f6901266731c4cb3b30b45bf41efa0e6ab70",
        strip_prefix = "spdlog-1.3.1",
        urls = [
            "https://github.com/unilang/spdlog/archive/v1.3.1.tar.gz",
            "https://github.com/gabime/spdlog/archive/v1.3.1.tar.gz",
        ],
    )
