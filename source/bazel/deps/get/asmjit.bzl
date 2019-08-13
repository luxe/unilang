load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def asmjit():
    http_archive(
        name = "asmjit",
        build_file = "//bazel/deps/build_files:asmjit.BUILD",
        sha256 = "e1097de5bf57d6801dd38373b6c495b4612f74ecd9bff5db9aa4db4ab93c76a2",
        strip_prefix = "asmjit-3d510b3540776d4961f5eac83af3643d31cde18b",
        urls = [
            "https://github.com/unilang/asmjit/archive/3d510b3540776d4961f5eac83af3643d31cde18b.tar.gz",
            "https://github.com/asmjit/asmjit/archive/3d510b3540776d4961f5eac83af3643d31cde18b.tar.gz",
        ],
    )
