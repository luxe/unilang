load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def tbb():
    http_archive(
        name = "tbb",
        build_file = "//bazel/deps/build_files:tbb.BUILD",
        sha256 = "4d149895826cea785cd3b9a14f4aa743b6ef0df520eca7ee27d438fdc3d73399",
        strip_prefix = "tbb-2019",
        urls = [
            "https://github.com/unilang/tbb/archive/2019.tar.gz",
            "https://github.com/01org/tbb/archive/2019.tar.gz",
        ],
    )
