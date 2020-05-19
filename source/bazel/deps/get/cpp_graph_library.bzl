load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def cppGraphLibrary():
    http_archive(
        name = "cpp_graph_library",
        build_file = "//bazel/deps/build_files:cpp_graph_library.BUILD",
        sha256 = "25e596035bbf73d19b1de758967757cb257110777e9aaff9bec28511d97ff806",
        strip_prefix = "Cpp-Graph-Library-e2dd887c2e38fabf1618628ab2c714aafe67c684",
        urls = [
            "https://github.com/unilang/Cpp-Graph-Library/archive/e2dd887c2e38fabf1618628ab2c714aafe67c684.tar.gz",
            "https://github.com/minyc510/Cpp-Graph-Library/archive/e2dd887c2e38fabf1618628ab2c714aafe67c684.tar.gz",
        ],
    )
