# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def librepr():
    http_archive(
        name="librepr" ,
        build_file="//bazel/deps/librepr:build.BUILD" ,
        sha256="474d1c6590e3d78ae9082d770a114b11b23e8c26855c2f728dbdecab25737efd" ,
        strip_prefix="librepr-bd5e1f745c59966588e67d475c62be61ded9dc8d" ,
        urls = [
            "https://github.com/Unilang/librepr/archive/bd5e1f745c59966588e67d475c62be61ded9dc8d.tar.gz",
        ],
    )
