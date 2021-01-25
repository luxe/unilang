load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def openssl():
    http_archive(
        name = "openssl",
        build_file = "//bazel/deps/build_files:openssl.BUILD",
        patches = ["//bazel/deps/build_files:openssl.patch"],
        sha256 = "fb6b5de486f1739dc34f2854a0c8f94d13c130eb9c4876cad73b3d40996f8ba6",
        strip_prefix = "openssl-OpenSSL_1_1_1",
        urls = [
            "https://github.com/unilang/openssl/archive/OpenSSL_1_1_1.tar.gz",
            "https://github.com/openssl/openssl/archive/OpenSSL_1_1_1.tar.gz",
        ],
    )
