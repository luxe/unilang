load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def open_cv_testdata():
    http_archive(
        name = "opencv_testdata",
        build_file = "//bazel/deps/build_files:opencv_testdata.BUILD",
        sha256 = "dbdab9548b6365ca63f5d4d3a2b27cecd03644a6898cc98c05f3b129a46b416c",
        strip_prefix = "opencv_extra-3.4.3",
        urls = [
            "https://github.com/opencv/opencv_extra/archive/3.4.3.tar.gz",
        ],
    )