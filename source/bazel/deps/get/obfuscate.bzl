load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def obfuscate():
    http_archive(
        name = "obfuscate",
        build_file = "//bazel/deps/build_files:obfuscate.BUILD",
        sha256 = "fda8221e08853a2d15e4c9004ceaf96ecb0fd5f86830d48dff0b218c6fc63353",
        strip_prefix = "Obfuscate-88915d0afa46448570207e36aa8cc5f714709c50",
        urls = [
            "https://github.com/unilang/Obfuscate/archive/88915d0afa46448570207e36aa8cc5f714709c50.tar.gz",
            "https://github.com/adamyaxley/Obfuscate/archive/88915d0afa46448570207e36aa8cc5f714709c50.tar.gz",
        ],
    )
