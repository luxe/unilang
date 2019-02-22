load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def open_cv():
    http_archive(
        name = "opencv",
        build_file = "//bazel/deps/build_files:opencv.BUILD",
        sha256 = "4eef85759d5450b183459ff216b4c0fa43e87a4f6aa92c8af649f89336f002ec",
        strip_prefix = "opencv-3.4.3",
        urls = [
            "https://github.com/opencv/opencv/archive/3.4.3.tar.gz",
        ],
    )