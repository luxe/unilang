load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def csv():
    http_archive(
        name = "csv",
        build_file = "//bazel/deps/build_files:csv.BUILD",
        sha256 = "148640bf0cad34c5b6e6886cfea03cd79fe33d67606f18668012ecdb070fd9f0",
        strip_prefix = "csv-13e04e5b31b585855c7d7e7f3c65e47ae863569b",
        urls = [
            "https://github.com/unilang/csv/archive/13e04e5b31b585855c7d7e7f3c65e47ae863569b.tar.gz",
            "https://github.com/p-ranav/csv/archive/13e04e5b31b585855c7d7e7f3c65e47ae863569b.tar.gz",
        ],
    )
