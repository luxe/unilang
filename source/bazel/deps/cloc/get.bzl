# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def cloc():
    http_archive(
        name="cloc" ,
        build_file="//bazel/deps/cloc:build.BUILD" ,
        sha256="da1a0de6d8ce2f4e80fa7554cf605f86d97d761b4ffd647df9b01c4658107dba" ,
        strip_prefix="cloc-90070481081b6decd9446d57a35176da3a6d8fbc" ,
        urls = [
            "https://github.com/Unilang/cloc/archive/90070481081b6decd9446d57a35176da3a6d8fbc.tar.gz",
        ],
    )
