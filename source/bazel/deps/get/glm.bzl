load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def glm():
    http_archive(
        name = "glm",
        build_file = "//bazel/deps/build_files:glm.BUILD",
        sha256 = "51b79f24e75bc239dcec184f0c349b093482ddf12cbd3e255776106ac083e4ff",
        strip_prefix = "glm-67d647ae4645a9787c1f87efa3279e8ec5f506e3",
        urls = [
            "https://github.com/unilang/glm/archive/67d647ae4645a9787c1f87efa3279e8ec5f506e3.tar.gz",
            "https://github.com/g-truc/glm/archive/67d647ae4645a9787c1f87efa3279e8ec5f506e3.tar.gz",
        ],
    )
