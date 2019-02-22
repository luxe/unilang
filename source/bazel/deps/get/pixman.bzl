load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def pixman():
    http_archive(
        name = "pixman",
        build_file = "//bazel/deps/build_files:pixman.BUILD",
        sha256 = "21b6b249b51c6800dc9553b65106e1e37d0e25df942c90531d4c3997aa20a88e",
        strip_prefix = "pixman-0.34.0",
        urls = [
            "https://www.cairographics.org/releases/pixman-0.34.0.tar.gz",
        ],
    )