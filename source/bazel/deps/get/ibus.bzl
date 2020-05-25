# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/reflexive_refresh

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def ibus():
    http_archive(
        name = "ibus",
        build_file = "//bazel/deps/build_files:ibus.BUILD",
        sha256 = "d2fee505277e2d168678ad49eaf91f57203cb4ef68c843981faca7f15e67500c",
        strip_prefix = "ibus-f591381e3c892947ecaffe9131b9039ab9014498",
        urls = [
            "https://github.com/Unilang/ibus/archive/f591381e3c892947ecaffe9131b9039ab9014498.tar.gz",
        ],
        patches = [
            "//bazel/deps/build_files:ibus_config.patch",
        ],
        patch_args = [
            "-p1",
        ],
    )
