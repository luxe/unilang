load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def expat():
    http_archive(
        name = "expat",
        build_file = "//bazel/deps/build_files:expat.BUILD",
        #patches = ["//bazel/deps/build_files:expat.patch"],
        sha256 = "35133afefe3ce180cf368efb49b04642249e3b2dc50846f525ee5609939bb45f",
        strip_prefix = "libexpat-67fc5c1cab8b8f72729ca5b0a97f7adb466c9f8a",
        urls = [
            "https://github.com/unilang/libexpat/archive/5801a1b70adeb59964be51e61ac753be8ebe75e8.tar.gz",
            "https://github.com/libexpat/libexpat/archive/5801a1b70adeb59964be51e61ac753be8ebe75e8.tar.gz",
        ],
    )
