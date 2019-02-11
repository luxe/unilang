load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def abseil():
    http_archive(
        name = "com_google_absl",
        sha256 = "57b7817ad91856399a77300349eda39d2edae2c3c037d453fee0a16b85e92a4d",
        strip_prefix = "abseil-cpp-48cd2c3f351ff188bc85684b84a91b6e6d17d896",
        urls = [
            "https://github.com/abseil/abseil-cpp/archive/48cd2c3f351ff188bc85684b84a91b6e6d17d896.zip",
        ],
    )
