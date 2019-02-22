load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def sqlite3():
    http_archive(
        name = "sqlite3",
        build_file = "//bazel/deps/build_files:sqlite3.BUILD",
        sha256 = "ad68c1216c3a474cf360c7581a4001e952515b3649342100f2d7ca7c8e313da6",
        strip_prefix = "sqlite-amalgamation-3240000",
        urls = [
            "https://www.sqlite.org/2018/sqlite-amalgamation-3240000.zip",
        ],
    )