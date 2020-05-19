load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def sqliteOrm():
    http_archive(
        name = "sqlite_orm",
        build_file = "//bazel/deps/build_files:sqlite_orm.BUILD",
        sha256 = "7c2a02ec48e48078a61817627c09ef0a5540b06b5fb2990976f63b18d05c4c83",
        strip_prefix = "sqlite_orm-de4e2bd01040090b163e1ee87f1dd6600e143270",
        urls = [
            "https://github.com/unilang/sqlite_orm/archive/de4e2bd01040090b163e1ee87f1dd6600e143270.tar.gz",
            "https://github.com/fnc12/sqlite_orm/archive/de4e2bd01040090b163e1ee87f1dd6600e143270.tar.gz",
        ],
    )
