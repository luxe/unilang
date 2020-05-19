load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def backwardCpp():
    http_archive(
        name = "backward_cpp",
        build_file = "//bazel/deps/build_files:backward_cpp.BUILD",
        sha256 = "16ea32d5337735ed3e7eacd71d90596a89bc648c557bb6007c521a2cb6b073cc",
        strip_prefix = "backward-cpp-aa3f253efc7281148e9159eda52b851339fe949e",
        urls = [
            "https://github.com/unilang/backward-cpp/archive/aa3f253efc7281148e9159eda52b851339fe949e.tar.gz",
            "https://github.com/bombela/backward-cpp/archive/aa3f253efc7281148e9159eda52b851339fe949e.tar.gz",
        ],
    )
