load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def yamlCpp():
    http_archive(
        name = "yaml-cpp",
        build_file = "//bazel/deps/build_files:yaml-cpp.BUILD",
        sha256 = "e4d8560e163c3d875fd5d9e5542b5fd5bec810febdcba61481fe5fc4e6b1fd05",
        strip_prefix = "yaml-cpp-yaml-cpp-0.6.2",
        urls = [
            "https://github.com/unilang/yaml-cpp/archive/yaml-cpp-0.6.2.tar.gz",
            "https://github.com/jbeder/yaml-cpp/archive/yaml-cpp-0.6.2.tar.gz",
        ],
    )
