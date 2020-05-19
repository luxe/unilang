load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def chineseSyllableSounds():
    http_archive(
        name = "chinese_syllable_sounds",
        build_file = "//bazel/deps/build_files:chinese_syllable_sounds.BUILD",
        sha256 = "52849b2317e897ba333a9ae0dd55f7187a7198619fab74e555e9919c750942a0",
        strip_prefix = "chinese_syllable_sounds-042305a69752a5beef8e6e0f66942edc370f7dcc",
        urls = [
            "https://github.com/unilang/chinese_syllable_sounds/archive/042305a69752a5beef8e6e0f66942edc370f7dcc.tar.gz",
        ],
    )