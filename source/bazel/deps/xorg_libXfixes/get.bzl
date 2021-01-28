# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def xorgLibXfixes():
    http_archive(
        name = "xorg_libXfixes",
        build_file = "//bazel/deps/xorg_libXfixes:build.BUILD",
        sha256 = "ed38275d3b662b7b9be6da5db75b891f596a52bf21dcb1547324d76c37347b99",
        strip_prefix = "xorg-libXfixes-174a94975af710247719310cfc53bd13e1f3b44d",
        urls = [
            "https://github.com/Unilang/xorg-libXfixes/archive/174a94975af710247719310cfc53bd13e1f3b44d.tar.gz",
        ],
        patches = [
            "//bazel/deps/xorg_libXfixes/patches:p1.patch",
        ],
        patch_args = [
            "-p1",
        ],
    )
