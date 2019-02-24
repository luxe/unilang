load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def glfw():
    http_archive(
        name = "glfw",
        build_file = "//bazel/deps/build_files:glfw.BUILD",
        sha256 = "e10f0de1384d75e6fc210c53e91843f6110d6c4f3afbfb588130713c2f9d8fe8",
        strip_prefix = "glfw-3.2.1",
        urls = [
             "https://github.com/Unilang/glfw/archive/3.2.1.tar.gz",
             "https://github.com/glfw/glfw/archive/3.2.1.tar.gz"
             ],
    )
