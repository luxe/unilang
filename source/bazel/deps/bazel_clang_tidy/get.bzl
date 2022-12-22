# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_file")
load("//bazel/deps:deps_config.bzl", "main_mirror_url")

def bazelClangTidy():
    http_archive(
        name="bazel_clang_tidy" ,
        sha256="2c2d7e290d78c0020c60f07cec6e3820cce64c285153de8e96637027ee5e3b8e" ,
        strip_prefix="bazel_clang_tidy-31d62bf825a94468b3d35c5ffd4e014e1c0ff566" ,
        urls = [
            main_mirror_url("bazel_clang_tidy","31d62bf825a94468b3d35c5ffd4e014e1c0ff566"),
        ],
    )
