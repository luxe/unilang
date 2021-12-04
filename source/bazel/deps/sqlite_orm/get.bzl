# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def sqliteOrm():
    http_archive(
        name="sqlite_orm" ,
        build_file="//bazel/deps/sqlite_orm:build.BUILD" ,
        sha256="7c2a02ec48e48078a61817627c09ef0a5540b06b5fb2990976f63b18d05c4c83" ,
        strip_prefix="sqlite_orm-de4e2bd01040090b163e1ee87f1dd6600e143270" ,
        urls = [
            "https://github.com/Unilang/sqlite_orm/archive/de4e2bd01040090b163e1ee87f1dd6600e143270.tar.gz",
        ],
    )
