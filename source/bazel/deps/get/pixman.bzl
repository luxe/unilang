load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def pixman():
    http_archive(
        name = "pixman",
        build_file = "//bazel/deps/build_files:pixman.BUILD",
        patches = ["//bazel/deps/build_files:pixman.patch"],
        sha256 = "201917adc8a5be5074f9bddc5c3f5e514949f7fea5a801d04e3fb759af6c990f",
        strip_prefix = "pixman-6f8b8b383f3e9c2c8b9ec22fac73e9e84d0232d3",
        urls = [
            "https://github.com/unilang/pixman/archive/6f8b8b383f3e9c2c8b9ec22fac73e9e84d0232d3.tar.gz",
            "https://github.com/servo/pixman/archive/958bd334b3c17f529c80f2eeef4224f45c62f292.tar.gz",
            "https://www.cairographics.org/releases/pixman-0.34.0.tar.gz",
        ],
    )