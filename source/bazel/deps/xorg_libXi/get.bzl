# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def xorgLibXi():
    http_archive(
        name = "xorg_libXi",
        build_file = "//bazel/deps/xorg_libXi:build.BUILD",
        sha256 = "110301e384be0aa08eede5568681e5aebee96949922364262d464ed57eee5f83",
        strip_prefix = "xorg-libXi-e05da79a98775edb91ffe3de3b413f156bc4d6e7",
        urls = [
            "https://github.com/Unilang/xorg-libXi/archive/e05da79a98775edb91ffe3de3b413f156bc4d6e7.tar.gz",
        ],
        patches = [
            "//bazel/deps/xorg_libXi/patches:p1.patch",
        ],
        patch_args = [
            "-p1",
        ],
    )
