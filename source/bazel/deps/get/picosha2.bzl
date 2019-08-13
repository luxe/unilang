load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def picosha2():
    http_archive(
        name = "picosha2",
        build_file = "//bazel/deps/build_files:picosha2.BUILD",
        sha256 = "b2866ef6b22e4562a4cbec6aa2510e74edd34a4889ac952b09c2acfa7bb8f619",
        strip_prefix = "PicoSHA2-b699e6c900be6e00152db5a3d123c1db42ea13d0",
        urls = [
            "https://github.com/unilang/PicoSHA2/archive/b699e6c900be6e00152db5a3d123c1db42ea13d0.tar.gz",
            "https://github.com/okdshin/PicoSHA2/archive/b699e6c900be6e00152db5a3d123c1db42ea13d0.tar.gz",
        ],
    )
