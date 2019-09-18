load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def soloud():
    http_archive(
        name = "soloud",
        build_file = "//bazel/deps/build_files:soloud.BUILD",
        sha256 = "3b87374dfa5da58a6ebca6a23280fa5519728b7fb2607e4037988cabe7dbdb2c",
        strip_prefix = "soloud-6ee8ffb91a02764c7b8f331ee2177096d46bdd7c",
        urls = [
            "https://github.com/unilang/soloud/archive/6ee8ffb91a02764c7b8f331ee2177096d46bdd7c.tar.gz",
            "https://github.com/jarikomppa/soloud/archive/6ee8ffb91a02764c7b8f331ee2177096d46bdd7c.tar.gz",
        ],
    )