# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def libbf():
    http_archive(
        name="libbf" ,
        build_file="//bazel/deps/libbf:build.BUILD" ,
        sha256="09c868ef3dc62fb81d7128e8c3c0f9bb1de603192af7e83f25bf414598867bcb" ,
        strip_prefix="libbf-5478275d8a4e9a5cc163b44c34517c515bd898ec" ,
        urls = [
            "https://github.com/Unilang/libbf/archive/5478275d8a4e9a5cc163b44c34517c515bd898ec.tar.gz",
        ],
    )
