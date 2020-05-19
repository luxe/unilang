load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def minizCpp():
    http_archive(
        name = "miniz_cpp",
        build_file = "//bazel/deps/build_files:miniz_cpp.BUILD",
        sha256 = "6f0994a0ef9fb95ed8cf12aa36ae6fd6e99e087b384a155b6a0344a763424fc5",
        strip_prefix = "miniz-cpp-052335e4f7773368df07b26d2baedb0e6d4dbd38",
        urls = [
            "https://github.com/unilang/miniz-cpp/archive/052335e4f7773368df07b26d2baedb0e6d4dbd38.tar.gz",
            "https://github.com/tfussell/miniz-cpp/archive/052335e4f7773368df07b26d2baedb0e6d4dbd38.tar.gz",
        ],
    )
