# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/reflexive_refresh

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def python3():
    http_archive(
        name = "python3",
        build_file = "//bazel/deps/python3:build.BUILD",
        sha256 = "36592ee2910b399c68bf0ddad1625f2c6a359ab9a8253d676d44531500e475d4",
        strip_prefix = "python3-7f755fe87d217177603a27d9dcc2fedc979f0f1a",
        urls = [
            "https://github.com/Unilang/python3/archive/7f755fe87d217177603a27d9dcc2fedc979f0f1a.tar.gz",
        ],
        patch_cmds = [
            "sed -i '/HAVE_CRYPT_H/d'  usr/include/x86_64-linux-gnu/python3.6m/pyconfig.h",
        ],
    )