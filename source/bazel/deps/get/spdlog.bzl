load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def spdlog():
    http_archive(
        name = "spdlog",
        build_file = "//bazel/deps/build_files:spdlog.BUILD",
        sha256 = "867a4b7cedf9805e6f76d3ca41889679054f7e5a3b67722fe6d0eae41852a767",
        strip_prefix = "spdlog-1.2.1",
        urls = [
            "https://github.com/unilang/spdlog/releases/tag/v1.2.1",
            "https://github.com/gabime/spdlog/releases/tag/v1.2.1",
        ],
    )
