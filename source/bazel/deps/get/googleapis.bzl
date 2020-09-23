# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def googleapis():
    http_archive(
        name = "googleapis",
        build_file = "//bazel/deps/build_files:googleapis.BUILD",
        sha256 = "1ca9e4c0de992c44c3c95cf72c3b93ec4c14b8916e42703ecce0eaf41a908557",
        strip_prefix = "googleapis-3dbeac0d54125b123c8dfd39c774b37473c36944",
        patch_cmds = [
            "find . -name 'BUILD' -type f -delete",
            "find . -name 'WORKSPACE' -type f -delete",
            "find ./* -mindepth 1 -name 'BUILD.bazel' -type f -delete",
        ],
        urls = [
            "https://github.com/Unilang/googleapis/archive/3dbeac0d54125b123c8dfd39c774b37473c36944.tar.gz",
        ],
    )
