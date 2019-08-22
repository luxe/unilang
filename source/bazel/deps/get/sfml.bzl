load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def sfml():
    http_archive(
        name = "sfml",
        build_file = "//bazel/deps/build_files:sfml.BUILD",
        sha256 = "6b013624aa9a916da2d37180772031e963098494538f59a14f40e00db23c9077",
        strip_prefix = "SFML-257e50beb886f1edebeebbde1903169da4eca39f",
        urls = [
            "https://github.com/unilang/SFML/archive/257e50beb886f1edebeebbde1903169da4eca39f.tar.gz",
            "https://github.com/SFML/SFML/archive/86672a37246100f40077e692bc7130a8e4e87d2c.tar.gz",
        ],
    )
