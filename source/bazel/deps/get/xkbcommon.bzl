load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def xkbcommon():
    http_archive(
        name = "xkbcommon",
        build_file = "//bazel/deps/build_files:xkbcommon.BUILD",
        sha256 = "bb9b5784267331ac5bb1eed7c38d42ce85e545d7bf63168094c71fbb32093681",
        strip_prefix = "libxkbcommon-bdb009bb0cd925b062ec922bf031042d6209eb29",
        urls = [
            "https://github.com/unilang/libxkbcommon/archive/bdb009bb0cd925b062ec922bf031042d6209eb29.tar.gz",
            "https://github.com/xkbcommon/libxkbcommon/archive/25cd67daf7ef7a4bfe49a2b91b2fe085e36ae786.tar.gz",
        ],
    )
