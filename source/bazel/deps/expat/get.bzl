# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def expat():
    http_archive(
        name = "expat",
        build_file = "//bazel/deps/expat:build.BUILD",
        sha256 = "35133afefe3ce180cf368efb49b04642249e3b2dc50846f525ee5609939bb45f",
        strip_prefix = "libexpat-5801a1b70adeb59964be51e61ac753be8ebe75e8",
        urls = [
            "https://github.com/Unilang/libexpat/archive/5801a1b70adeb59964be51e61ac753be8ebe75e8.tar.gz",
        ],
        patches = [
            "//bazel/deps/expat/patches:p1.patch",
        ],
    )
