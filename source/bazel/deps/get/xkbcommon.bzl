load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def xkbcommon():
    http_archive(
        name = "xkbcommon",
        build_file = "//bazel/deps/build_files:xkbcommon.BUILD",
        sha256 = "5f066ae8ac1afcea8a7522f0fb23561bef57eb04d677ecfc31131dd8856b4479",
        strip_prefix = "libxkbcommon-25cd67daf7ef7a4bfe49a2b91b2fe085e36ae786",
        urls = [
            "https://github.com/unilang/libxkbcommon/archive/25cd67daf7ef7a4bfe49a2b91b2fe085e36ae786.tar.gz",
            "https://github.com/xkbcommon/libxkbcommon/archive/25cd67daf7ef7a4bfe49a2b91b2fe085e36ae786.tar.gz",
        ],
    )
