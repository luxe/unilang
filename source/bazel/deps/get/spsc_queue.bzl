load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def spsc_queue():
    http_archive(
        name = "spsc_queue",
        build_file = "//bazel/deps/build_files:spsc_queue.BUILD",
        sha256 = "c3fed3c2654f45043f4394e580e8634e3f53b17088fb94bdbafdc4d265d1d2cf",
        strip_prefix = "SPSCQueue-10c00a5c0f1bcfcd4f4e135d143f00b409254026",
        urls = [
            "https://github.com/unilang/SPSCQueue/archive/10c00a5c0f1bcfcd4f4e135d143f00b409254026.tar.gz",
            "https://github.com/rigtorp/SPSCQueue/archive/10c00a5c0f1bcfcd4f4e135d143f00b409254026.tar.gz",
        ],
    )
