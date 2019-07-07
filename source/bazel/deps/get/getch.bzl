load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def getch():
    http_archive(
        name = "getch",
        build_file = "//bazel/deps/build_files:getch.BUILD",
        sha256 = "f86ae02feff29ae4ce662d55bb7735015e79fad84b14977ac3b900b5e0ea1cec",
        strip_prefix = "simple-getch-e86fb3d42e290de31995849025e3474b714d35c7",
        urls = [
            "https://github.com/unilang/simple-getch/archive/e86fb3d42e290de31995849025e3474b714d35c7.tar.gz",
            "https://github.com/mouuff/simple-getch/archive/e86fb3d42e290de31995849025e3474b714d35c7.tar.gz",
        ],
    )