load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def sfml():
    http_archive(
        name = "sfml",
        build_file = "//bazel/deps/build_files:sfml.BUILD",
        sha256 = "fc015c546724244ac753d34d54ad5cc65722a18292a60ecd0d0e8b0c681fd014",
        strip_prefix = "SFML-86672a37246100f40077e692bc7130a8e4e87d2c",
        urls = [
            "https://github.com/unilang/SFML/archive/86672a37246100f40077e692bc7130a8e4e87d2c.tar.gz",
            "https://github.com/SFML/SFML/archive/86672a37246100f40077e692bc7130a8e4e87d2c.tar.gz",
        ],
    )
