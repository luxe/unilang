load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def libpng():
    http_archive(
        name = "libpng",
        build_file = "//bazel/deps/build_files:libpng.BUILD",
        patches = ["//bazel/deps/build_files:libpng.patch"],
        sha256 = "16ca00dca64c72f293a27af290a349a0d9ae2ef7336f6bd9caae612f67ffba8b",
        strip_prefix = "libpng-301f7a14295a3bdfaf406dbb5004d0784dc137ea",
        urls = [
            "https://github.com/glennrp/libpng/archive/301f7a14295a3bdfaf406dbb5004d0784dc137ea.tar.gz",
        ],
    )