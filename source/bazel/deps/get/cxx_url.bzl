load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def cxx_url():
    http_archive(
        name = "cxx_url",
        build_file = "//bazel/deps/build_files:cxx_url.BUILD",
        sha256 = "9b4ba36ee6579be8c367659ea3768ddb7745a9da00d1ac1e5cfd996bf5d40511",
        strip_prefix = "CxxUrl-7e7af0ce97b1021eaaf687ced1f65a5bd3e7d548",
        urls = [
            "https://github.com/unilang/CxxUrl/archive/7e7af0ce97b1021eaaf687ced1f65a5bd3e7d548.tar.gz",
            "https://github.com/chmike/CxxUrl/archive/7e7af0ce97b1021eaaf687ced1f65a5bd3e7d548.tar.gz",
        ],
    )